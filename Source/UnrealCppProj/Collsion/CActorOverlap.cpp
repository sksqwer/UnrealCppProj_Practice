// Fill out your copyright notice in the Description page of Project Settings.


#include "CActorOverlap.h"
#include "global.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"

// Sets default values
ACActorOverlap::ACActorOverlap()
{
	PrimaryActorTick.bCanEverTick = true;

	CHelpers::CreateComponent<USceneComponent>(this, &Scene, "Scene");
	CHelpers::CreateComponent<UBoxComponent>(this, &Box, "Box", Scene);
	CHelpers::CreateComponent<UTextRenderComponent>(this, &Text, "Text", Scene);


	Text->SetRelativeLocation(FVector(0, 0, 0));
	Box->SetRelativeScale3D(FVector(3));
	Box->bHiddenInGame = false;

	Text->SetRelativeLocation(FVector(0, 0, 100));
	Text->SetRelativeRotation(FRotator(0, 0, -180));
	Text->SetRelativeScale3D(FVector(2));
	Text->TextRenderColor = FColor::Red;
	Text->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	Text->Text = FText::FromString(GetName());

}

// Called when the game starts or when spawned
void ACActorOverlap::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &ACActorOverlap::ActorBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &ACActorOverlap::ActorEndOverlap);
}

void ACActorOverlap::ActorBeginOverlap(AActor* overlappedActor, AActor* OtherActor)
{
	FString str = "";
	str.Append(__FUNCDNAME__);
	str.Append(OtherActor->GetName());
	CLog::Log(str);
	is_overlap = true;
	
}

void ACActorOverlap::ActorEndOverlap(AActor* overlappedActor, AActor* OtherActor)
{
	FString str = "";
	str.Append(__FUNCDNAME__);
	str.Append(OtherActor->GetName());
	CLog::Log(str);
	is_overlap = false;
}

// Called every frame
void ACActorOverlap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(is_overlap)
	{
		DrawDebugPoint(GetWorld(), GetActorLocation(), 100, FColor::Emerald);
	}

}
