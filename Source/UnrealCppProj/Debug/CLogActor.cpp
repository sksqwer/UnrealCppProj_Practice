// Fill out your copyright notice in the Description page of Project Settings.


#include "CLogActor.h"

#include "global.h"

// Sets default values
ACLogActor::ACLogActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACLogActor::BeginPlay()
{
	Super::BeginPlay();

	CLog::Print(10);
	
}

// Called every frame
void ACLogActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

