#include "CCDSolver.h"

CCDSolver::CCDSolver() {
	mNumSteps = 15;
	mThreshold = 0.00001f;
}

unsigned int CCDSolver::Size() {
	return mIKChain.size();
}

void CCDSolver::Resize(unsigned int newSize) {
	mIKChain.resize(newSize);
}

Transform& CCDSolver::operator[](unsigned int index) {
	return mIKChain[index];
}

unsigned int CCDSolver::GetNumSteps() {
	return mNumSteps;
}

void CCDSolver::SetNumSteps(unsigned int numSteps) {
	mNumSteps = numSteps;
}

float CCDSolver::GetThreshold() {
	return mThreshold;
}

void CCDSolver::SetThreshold(float value) {
	mThreshold = value;
}

Transform CCDSolver::GetGlobalTransform(unsigned int index) {
	unsigned int size = (unsigned int)mIKChain.size();
	Transform world = mIKChain[index];

	//直到变换到根结点
	for (int i = (int)index - 1; i >= 0; --i) {
		world = combine(mIKChain[i], world);
	}
	return world;
}

bool CCDSolver::Solve(const Transform& target) 
{
	unsigned int size = Size();
	if (size == 0) { return false; }
	unsigned int last = size - 1;
	float thresholdSq = mThreshold * mThreshold;
	vec3 goal = target.position;

	//每一步迭代
	for (unsigned int i = 0; i < mNumSteps; ++i) 
	{
		//获得末端节点的位置，如果和目标位置足够近，那么就提前返回true
		vec3 effector = GetGlobalTransform(last).position;
		if (lenSq(goal - effector) < thresholdSq) {
			return true;
		}


		//每一步迭代就是将当前节点与末端点之间的连线方向旋转到当前节点与目标连线的方向，从倒数第二个节点开始旋转，因为最后一个节点旋转不产生影响
		for (int j = (int)size - 2; j >= 0; --j) 
		{
			effector = GetGlobalTransform(last).position;

			//获得当前节点的世界变换
			Transform world = GetGlobalTransform(j);
			vec3 position = world.position;
			quat rotation = world.rotation;

			vec3 toEffector = effector - position;    //由当前节点指向末端节点
			vec3 toGoal = goal - position;            //由当前节点指向目标节点

			//计算从toEffector方向到toGoal方向的旋转四元数
			quat effectorToGoal;
			if (lenSq(toGoal) > 0.00001f) {
				effectorToGoal = fromTo(toEffector, toGoal);
			}

			//更新当前节点的局部旋转
			quat worldRotated = rotation * effectorToGoal;
			quat localRotate = worldRotated * inverse(rotation);
			mIKChain[j].rotation = localRotate * mIKChain[j].rotation;

			//判断末端节点和目标位置是否足够近
			effector = GetGlobalTransform(last).position;
			if (lenSq(goal - effector) < thresholdSq) {
				return true;
			}
		}
	}

	return false;
} // End CCDSolver::Solve function