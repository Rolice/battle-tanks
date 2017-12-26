// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Projectile.h"


// Sets default values
ATank::ATank() {
    // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;

    TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));

}

// Called when the game starts or when spawned
void ATank::BeginPlay() {
    Super::BeginPlay();

}

void ATank::AimAt(FVector HitLocation) {
    TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::SetBarrelReference(UTankBarrel *barrel) {
    TankAimingComponent->SetBarrelReference(barrel);
    Barrel = barrel;
}

void ATank::SetTurretReference(UTankTurret *turret) {
    TankAimingComponent->SetTurretReference(turret);
}

void ATank::Fire() {
    bool ready = FPlatformTime::Seconds() - LastFireTime > ReloadTime;

    if(!Barrel || !ready) {
        return;
    }

    // Spawn a new projectile at socket
    auto Projectile = GetWorld()->SpawnActor<AProjectile>(
        ProjectileBlueprint,
        Barrel->GetSocketLocation(FName("Projectile")),
        Barrel->GetSocketRotation(FName("Projectile"))
    );

    Projectile->Launch(LaunchSpeed);
    LastFireTime = FPlatformTime::Seconds();
}