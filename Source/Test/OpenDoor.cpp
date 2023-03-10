// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenDoor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (ActorThatOpens == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT(" ERROR: is not initialized"));
	}

	Owner = GetOwner();
	if (Owner == nullptr) UE_LOG(LogTemp, Error, TEXT(" ERROR: Owner not found !"));

	if (CloseDoorDelay == 0) 
	{
		CloseDoorDelay = 2.f;
	}

	
	
	// ...
	
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		OpenDoor();
		LastTimeOpenDoor = GetWorld()->GetTimeSeconds();
	}

	if (GetWorld()->GetTimeSeconds() - LastTimeOpenDoor >= CloseDoorDelay)
	{
		CloseDoor();
	}
	// ...
}

void UOpenDoor::OpenDoor()
{
	FRotator NewRotation;

	NewRotation = FRotator(0.f, OpenAngle, 0.f);
	Owner->SetActorRotation(NewRotation);
}

void UOpenDoor::CloseDoor()
{
	FRotator NewRotation;

	//this_thread::sleep_for(chrono::milliseconds(5000));
	NewRotation = FRotator(0.f, CloseAngle, 0.f);
	Owner->SetActorRotation(NewRotation);
}

