// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel; // Forward-declaration
class UTankTurret; // Forward-declaration

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UTankBarrel *Barrel = nullptr;
    UTankTurret *Turret = nullptr;

public:
	// Sets default values for this component's properties
	UTankAimingComponent();

	void AimAt(FVector HitLocation, float LaunchSpeed);
	void SetBarrelReference(UTankBarrel *barrel);
	void SetTurretReference(UTankTurret *turret);
	void Move(FVector AimDirection);

};
