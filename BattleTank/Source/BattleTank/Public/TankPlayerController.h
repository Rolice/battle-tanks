// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
    virtual void BeginPlay() override;
    virtual void Tick(float dt) override;
    ATank *GetControlledTank() const;
    
    // Starts the tank moving the barrel so that a shot would hit where the crosshair intersects the world
    void AimTowardsCrosshair();
    bool GetSightRayHitLocation(FVector &HitLocation) const;
    bool GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const;
    bool GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation) const;
    
    UPROPERTY(EditDefaultsOnly)
    float CrosshairXLocation = 0.5;
    
    UPROPERTY(EditDefaultsOnly)
    float CrosshairYLocation = 0.33333;

    UPROPERTY(EditDefaultsOnly)
    float LineTraceRange = 1000000;
};
