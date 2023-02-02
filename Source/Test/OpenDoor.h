// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"




DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);

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

	float GetTotalMassOfOverlappingActor();

	

private:
	UPROPERTY(EditAnywhere)
		ATriggerVolume * PressurePlate;
	/// <summary>
	/// Represent the angle of the door when it's open
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		float OpenAngle = 0.f;

	/// <summary>
	/// Represent the angle of the door when it's close
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		float CloseAngle = 90.f;

	/// <summary>
	/// Represent the delay when the door will close
	/// </summary>
	UPROPERTY(EditAnywhere)
		float CloseDoorDelay = 1.f;

	float LastTimeOpenDoor;

	float LimitMassWhenDoorOpen = 30.f;

	UPROPERTY(BlueprintAssignable)
		FDoorEvent OpenDoorRequest;

	UPROPERTY(BlueprintAssignable)
		FDoorEvent CloseDoorRequest;



	AActor* Owner;

	
	
};
