// Fill out your copyright notice in the Description page of Project Settings.

#include "global.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"
#include "CMulticastTrigger.h"
#include "Kismet/KismetArrayLibrary.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ACMulticastTrigger::ACMulticastTrigger()
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
void ACMulticastTrigger::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &ACMulticastTrigger::ActorBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &ACMulticastTrigger::ActorEndOverlap);


}

void ACMulticastTrigger::ActorBeginOverlap(AActor* overlappedActor, AActor* OtherActor)
{
	if(OnMultiLightBeginOverlap.IsBound())
	{
		int32 index = UKismetMathLibrary::RandomIntegerInRange(0, 2);

		FLinearColor color;
		color.R = UKismetMathLibrary::RandomFloatInRange(0, 1);
		color.G = UKismetMathLibrary::RandomFloatInRange(0, 1);
		color.B = UKismetMathLibrary::RandomFloatInRange(0, 1);
		color.A = 1.0f;

		OnMultiLightBeginOverlap.Broadcast(index, color);
	}

}

void ACMulticastTrigger::ActorEndOverlap(AActor* overlappedActor, AActor* OtherActor)
{


}