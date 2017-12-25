// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
    
    auto ControlledTank = GetControlledTank();
    auto PlayerTank = GetPlayerTank();
    
    if(!ControlledTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("TankAIController does not possess a tank."))
        return;
    }
    
    UE_LOG(LogTemp, Warning, TEXT("TankAIController possesses a tank %s"), *(ControlledTank->GetName()))
    
    if(!PlayerTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("No player tank found!"))
        return;
    }
    
    UE_LOG(LogTemp, Warning, TEXT("Player tank found is %s"), *(PlayerTank->GetName()))
}

void ATankAIController::Tick(float dt)
{
    Super::Tick(dt);

    if (!GetControlledTank() || !GetPlayerTank()) {
        return;
    }

    // TODO: Move towards the player

    GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

    // TODO: Fire if ready
}

ATank *ATankAIController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

ATank *ATankAIController::GetPlayerTank() const
{
    return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
