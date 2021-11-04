// Fill out your copyright notice in the Description page of Project Settings.


#include "CSweepTrigger.h"
#include "global.h"
#include "Components/TextRenderComponent.h"
#include "Components/BoxComponent.h"
#include "CExplosion.h"

// Sets default values
ACSweepTrigger::ACSweepTrigger()
{
	CHelpers::CreateComponent<USceneComponent>(this, &Scene, "Scene");
	CHelpers::CreateComponent<UBoxComponent>(this, &Box, "Box", Scene);
	CHelpers::CreateComponent<UTextRenderComponent>(this, &Text, "Text", Scene);

	Box->SetRelativeScale3D(FVector(3));
	Box->bHiddenInGame = false;


	Text->SetRelativeLocation(FVector(0, 0, 140));

	Text->SetRelativeLocation(FVector(0, 90, 0));
	Text->SetRelativeRotation(FRotator(0, 0, 0));
	Text->SetRelativeScale3D(FVector(2));
	Text->TextRenderColor = FColor::Red;
	Text->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	Text->Text = FText::FromString(GetName());
}

// Called when the game starts or when spawned
void ACSweepTrigger::BeginPlay()
{
	Super::BeginPlay();

	TArray<ACExplosion*> explosions;
	CHelpers::FindActor(GetWorld(), explosions);

	OnActorBeginOverlap.AddDynamic(explosions[0], &ACExplosion::ActorBeginOverlap);
	
}