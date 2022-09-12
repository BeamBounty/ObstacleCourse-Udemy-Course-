// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation= GetActorLocation();
	
}


// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation(); // Get Current Location
	CurrentLocation += (PlatformVelocity * DeltaTime); //Add Vector to that Location (Multiply by DeltaTime to make frame rate indepedent)
	SetActorLocation(CurrentLocation); // Set Location
	
	float DistanceMoved = FVector::Dist(StartLocation, CurrentLocation); //Every Frame, check how far platform has moved
	 
	if (DistanceMoved > DistMoved)
	{
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation += (MoveDirection * DistMoved);
		PlatformVelocity = -PlatformVelocity;
	}
	
}

