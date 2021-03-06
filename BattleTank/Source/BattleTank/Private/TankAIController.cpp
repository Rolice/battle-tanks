// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
}

void ATankAIController::Tick(float dt)
{
    Super::Tick(dt);

    auto ControlledTank = Cast<ATank>(GetPawn());
    auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

    if (!ControlledTank || !PlayerTank) {
        return;
    }

    // TODO: Move towards the player

    ControlledTank->AimAt(PlayerTank->GetActorLocation());

    // TODO: Fire if ready
    ControlledTank->Fire(); // Todo: Do not fire every frame
}