// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TEST_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	void OpenDoor();
	void CloseDoor();


private:
	UPROPERTY(EditAnywhere)
		ATriggerVolume * PressurePlate;

	UPROPERTY(EditAnywhere)
		float OpenAngle = 0.f;

	UPROPERTY(EditAnywhere)
		float CloseAngle = 90.f;

	UPROPERTY(EditAnywhere)
		float CloseDoorDelay = 1.f;

	float LastTimeOpenDoor;

	UPROPERTY(EditAnywhere)
		AActor* ActorThatOpens;

	AActor* Owner;

	
	
};
