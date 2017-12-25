// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() {
    Super::BeginPlay();

    auto ControlledTank = GetControlledTank();

    if (!ControlledTank) {
        UE_LOG(LogTemp, Warning, TEXT("No tank is possessed."))
        return;
    }

    UE_LOG(LogTemp, Warning, TEXT("TankPlayerController is possessing %s"), *(ControlledTank->GetName()))
}

void ATankPlayerController::Tick(float dt) {
    Super::Tick(dt);
    AimTowardsCrosshair();
}

ATank *ATankPlayerController::GetControlledTank() const {
    return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair() {
    if (!GetControlledTank()) {
        return;
    }

    FVector HitLocation;

    if (GetSightRayHitLocation(HitLocation)) {
        GetControlledTank()->AimAt(HitLocation);
    }
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &HitLocation) const {
    // Find crosshair position in pixel coordinates
    int32 ViewportSizeX, ViewportSizeY;
    GetViewportSize(ViewportSizeX, ViewportSizeY);
    FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);

    // De-project the screen position of crosshair to world  direction
    FVector LookDirection;
    if (GetLookDirection(ScreenLocation, LookDirection)) {
        return GetLookVectorHitLocation(LookDirection, HitLocation);
    }

    return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const {
    FVector CameraWorldLocation, WorldDirection;
    return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation) const {
    FHitResult Result;
    FVector Start = PlayerCameraManager->GetCameraLocation();
    FVector End = Start + (LookDirection * LineTraceRange);
    bool result = GetWorld()->LineTraceSingleByChannel(Result, Start, End, ECollisionChannel::ECC_Visibility);

    HitLocation = result ? Result.Location : FVector(0);

    return result;
}