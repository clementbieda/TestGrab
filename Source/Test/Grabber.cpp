// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FHitResult OutHit;

	//Declare position and rotation
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	
	//Declare the physics object collision
	FCollisionQueryParams TraceParameters;

	
	//Get location & rotation by the player view point
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(PlayerViewPointLocation, PlayerViewPointRotation);


	//Declare the end of the raycast line
	FVector End = ((PlayerViewPointRotation.Vector() * 1000.f) + PlayerViewPointLocation);


	//Trace the line on scene directly
	DrawDebugLine(GetWorld(), PlayerViewPointLocation, End, FColor::Green, false, 0, 0, 1);
	UE_LOG(LogTemp, Warning, TEXT("Viewpoint pos : %s & Viewport rot : %s"), *PlayerViewPointLocation.ToString(), *PlayerViewPointRotation.ToString());


	//Check for raycast only physics objects
	if (GetWorld()->LineTraceSingleByObjectType(
		OutHit, 
		PlayerViewPointLocation, 
		End, 
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), 
		TraceParameters
		))
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("You are hitting: %s"), *OutHit.GetActor()->GetActorLabel()));
	}

	//Get the physics handle
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();

	//Error security
	if (PhysicsHandle)
	{

		UE_LOG(LogTemp, Warning, TEXT("%s : Physics Handle ready to use"), *GetOwner()->GetActorLabel());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No Physics Handle component found on %s"), *GetOwner()->GetActorLabel());
	}


	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();

	if (InputComponent) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Input Component ready to use"));

		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
	}

	// ...
}
void UGrabber::Grab()
{
	UE_LOG(LogTemp, Warning, TEXT("Grab pressed"));
}
/*
FVector UGrabber::GetPlayerWorldPosition()
{
	//Declare position and rotation
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	//Get location & rotation by the player view point
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(PlayerViewPointLocation, PlayerViewPointRotation);


	return PlayerViewPointLocation;
}

FVector UGrabber::GetPlayerReach()
{
	//Declare position and rotation
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	//Get location & rotation by the player view point
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(PlayerViewPointLocation, PlayerViewPointRotation);

	return PlayerViewPointRotation.Vector() * 1000.f + PlayerViewPointLocation;
}

FHitResult UGrabber::GetFirstPhysicsBodyInReach() const
{
	return FHitResult();
}
*/

