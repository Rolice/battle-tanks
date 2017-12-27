// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
    RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
    auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
    auto Elevation = FMath::Clamp(RelativeRotation.Pitch + ElevationChange, MinimumElevation, MaximumElevation);

    SetRelativeRotation(FRotator(Elevation, 0, 0));
}