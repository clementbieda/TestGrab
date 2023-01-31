// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <PhysicsEngine/PhysicsHandleComponent.h>
#include "DrawDebugHelpers.h"
#include "Grabber.generated.h"


#define OUT


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TEST_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	UPROPERTY(EditAnywhere)
		UInputComponent* InputComponent = nullptr;


	float reachEndDistance = 100.f;

	void Grab();

	void Release();

	void GetPhysicsHandle();

	void SetUpInputComponent();

	FVector GetReachLineStart() const;
	FVector GetReachLineEnd() const;

	FHitResult GetFirstPhysicsBodyInReach();

	//FVector GetPlayerWorldPosition();

	//FVector GetPlayerReach();

	//FHitResult GetFirstPhysicsBodyInReach() const;
};
