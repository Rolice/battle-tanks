// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
    // TODO: Clamp actual throttle to disable OMV over-drive
    auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
    auto ForceLocation = GetComponentLocation();
    auto Tank = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

    Tank->AddForceAtLocation(ForceApplied, ForceLocation);
}
