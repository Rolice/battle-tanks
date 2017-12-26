// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent() {
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = false;

    // ...
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed) {
    if (!Barrel || !Turret) {
        return;
    }

    FVector LaunchVelocity = FVector(0);
    FVector Start = Barrel->GetSocketLocation(FName("Projectile"));

    bool projected = UGameplayStatics::SuggestProjectileVelocity(this, LaunchVelocity, Start, HitLocation, LaunchSpeed,
                                                                 false, 0, 0,
                                                                 ESuggestProjVelocityTraceOption::DoNotTrace);

    if (!projected) {
        return;
    }

    auto AimDirection = LaunchVelocity.GetSafeNormal();
    Move(AimDirection);
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel *barrel) {
    if (!barrel) {
        return;
    }

    Barrel = barrel;
}

void UTankAimingComponent::SetTurretReference(UTankTurret *turret) {
    if (!turret) {
        return;
    }

    Turret = turret;
}

void UTankAimingComponent::Move(FVector AimDirection) {
    auto DeltaRotator = AimDirection.Rotation() - Barrel->GetForwardVector().Rotation();

    Barrel->Elevate(DeltaRotator.Pitch);
    Turret->Rotate(DeltaRotator.Yaw);
}