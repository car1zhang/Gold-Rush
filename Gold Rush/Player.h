#pragma once

#include "stdafx.h"

class Player
{
public: 
	// Constructor and destructor
	Player(class Game* game, class Controller* controller);
	~Player();

	void Update(float deltaTime);

	void ComputeWorldTransform();
	Matrix4 GetWorldTransform() const { return mWorldTransform; }

	// Getters and Setters
	Vector2 GetPos() const { return mPos; }
	Vector2 GetPixPos() const { return mPixPos; }
	bool GetRecomputeWorldTransform() const { return mRecomputeWorldTransform; }
	bool GetFacing() const { return mFacing; }
	void SetFacing(bool facing) { mFacing = facing; }

private:
	// Member variables
	class Game* mGame;
	class Controller* mController;
	Vector2 mPos;
	Vector2 mPixPos;
	Vector2 mVel;
	float mScale;
	bool mFacing; // true = right
	bool mRecomputeWorldTransform;
	Matrix4 mWorldTransform;
	std::map<char, SDL_Scancode> mControls;
	bool mAtCheckpoint;
	float mOxygen;
};