// Fill out your copyright notice in the Description page of Project Settings.


#include "CTrigger.h"
#include "global.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"
#include "Kismet/KismetArrayLibrary.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ACTrigger::ACTrigger()
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
void ACTrigger::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &ACTrigger::ActorBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &ACTrigger::ActorEndOverlap);
}

void ACTrigger::ActorBeginOverlap(AActor* overlappedActor, AActor* OtherActor)
{
	if (OnBoxLightBeginOverlap.IsBound())
		OnBoxLightBeginOverlap.Execute();

	if(OnBoxLightRandomBeginOverlap.IsBound())
	{
		FLinearColor color;
		color.R = UKismetMathLibrary::RandomFloatInRange(0, 1);
		color.G = UKismetMathLibrary::RandomFloatInRange(0, 1);
		color.B = UKismetMathLibrary::RandomFloatInRange(0, 1);
		color.A = 1.0f;

		FString str = OnBoxLightRandomBeginOverlap.Execute(color);
		CLog::Log(str);
		
	}

}

void ACTrigger::ActorEndOverlap(AActor* overlappedActor, AActor* OtherActor)
{
	if (OnBoxLightEndOverlap.IsBound())
		OnBoxLightEndOverlap.Execute();
}

