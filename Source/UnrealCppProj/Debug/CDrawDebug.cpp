// Fill out your copyright notice in the Description page of Project Settings.


#include "CDrawDebug.h"

#include "global.h"

// Sets default values
ACDrawDebug::ACDrawDebug()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InitLocation[0] = FVector::ZeroVector;
	InitLocation[1] = FVector(0.0f, 400.0f, 0.0f);
	InitLocation[2] = FVector(0.0f, 1000.0f, 0.0f);
	InitLocation[3] = FVector(0.0f, 1600.0f, 0.0f);
	InitLocation[4] = FVector(300.0f, 1000.0f, 0.0f);

	Box = FBox(FVector(-50.0f, -100.0f, -50.0f), 
		FVector(50.0f, 100.0f, 50.0f));
	Transform.SetLocation(FVector(200.0f, 1600.0f, 0.0f));

}

// Called when the game starts or when spawned
void ACDrawDebug::BeginPlay()
{
	Super::BeginPlay();

	for (int32 i = 0; i < 5; i++)
		Location[i] = InitLocation[i] + GetActorLocation();

	DrawDebugBox(GetWorld(), Location[0] + Box.GetCenter(), Box.GetExtent(), FColor::Red, true);
	
}

// Called every frame
void ACDrawDebug::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (int32 i = 0; i < 5; i++)
		Location[i] = InitLocation[i] + GetActorLocation();

	DrawDebugSolidBox(GetWorld(), Location[0], Box.GetExtent(), FColor::Blue);

	//DrawDebugPoint(GetWorld(), Location[1], 100, FColor::Black);

	DrawDebugSphere(GetWorld(), Location[2], 100, 10, FColor::Green);

	DrawDebugCircle(GetWorld(), Location[3], 100, 50, FColor::Silver);

	DrawDebugLine(GetWorld(), Location[2], Location[3], FColor::Magenta, false, -1, 0, 10);

	FVector location = Location[1];
	location.X += 100;
	location.Z += 100;
	location.Y += sin(GetWorld()->GetTimeSeconds() * 3.0f) * 300.0f;

	DrawDebugPoint(GetWorld(), location, 100, FColor::Yellow);

	DrawDebugDirectionalArrow(GetWorld(), location, Location[3], 100, FColor::Emerald);

}

