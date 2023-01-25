// Fill out your copyright notice in the Description page of Project Settings.


#include "TablePosition.h"

// Sets default values for this component's properties
UTablePosition::UTablePosition()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTablePosition::BeginPlay()
{
	Super::BeginPlay();

	FString OwnName = GetOwner()->GetActorLabel();
	FVector ActorLocation = GetOwner()->GetActorLocation();

	FString ActorPosition = GetOwner()->GetTransform().GetLocation().ToString();

	UE_LOG(LogTemp, Warning, TEXT("%s is at %s"), *OwnName, *ActorPosition);

	FRotator ActorRotation = GetOwner()->GetActorRotation();
	FString ActorRotate = GetOwner()->GetTransform().GetRotation().ToString();

	UE_LOG(LogTemp, Warning, TEXT("%s is at %s"), *OwnName, *ActorRotate);

	FRotator MyRotation = FRotator(0.f, 90.f, 0.f);
	GetOwner()->SetActorRotation(MyRotation);

	

	// ...
	
}


// Called every frame
void UTablePosition::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// on every frame change rotationg for a smooth rotating actor




	// ...
}

