// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialize(UTankTrack *left, UTankTrack *right) {
    if (!left || !right) {
        return;
    }

    LeftTrack = left;
    RightTrack = right;
}

void UTankMovementComponent::IntendMoveForward(float Throw) {
    UE_LOG(LogTemp, Warning, TEXT("Intend to move forward with throw: %f"), Throw)

    LeftTrack->SetThrottle(Throw);
    RightTrack->SetThrottle(Throw);

    // TODO: Prevent double speed-up due to dual controls usage
}