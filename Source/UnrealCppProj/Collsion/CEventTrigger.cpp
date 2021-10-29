// Fill out your copyright notice in the Description page of Project Settings.


#include "CEventTrigger.h"
#include "global.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"
#include "Kismet/KismetArrayLibrary.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ACEventTrigger::ACEventTrigger()
{
	CHelpers::CreateComponent<USceneComponent>(this, &Scene, "Scene");
	CHelpers::CreateComponent<UBoxComponent>(this, &Box, "Box", Scene);
	CHelpers::CreateComponent<UTextRenderComponent>(this, &Text, "Text", Scene);


	Text->SetRelativeLocation(FVector(0, 0, 0));
	Box->SetRelativeScale3D(FVector(3));
	Box->bHiddenInGame = false;

	Text->SetRelativeLocation(FVector(0, 0, 100));
	Text->SetRelativeRotation(FRotator(0, 0, 0));
	Text->SetRelativeScale3D(FVector(2));
	Text->TextRenderColor = FColor::Red;
	Text->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	Text->Text = FText::FromString(GetName());

}

// Called when the game starts or when spawned
void ACEventTrigger::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &ACEventTrigger::ActorBeginOverlap);
	
}

void ACEventTrigger::ActorBeginOverlap(AActor* overlappedActor, AActor* OtherActor)
{
	if(OnEventTrigger.IsBound())
	{
		int32 index = UKismetMathLibrary::RandomIntegerInRange(0, 2);
		OnEventTrigger.Broadcast(index);
	}
}