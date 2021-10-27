// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CTrigger.generated.h"

DECLARE_DELEGATE(FBoxLightBeingOverlap);

UCLASS()
class UNREALCPPPROJ_API ACTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	bool is_overlap = false;

private:
	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* Scene;

	UPROPERTY(VisibleDefaultsOnly)
		class UBoxComponent* Box;

	UPROPERTY(VisibleDefaultsOnly)
		class UTextRenderComponent* Text;

private:
	UFUNCTION()
		void ActorBeginOverlap(AActor* overlappedActor, AActor* OtherActor);

	UFUNCTION()
		void ActorEndOverlap(AActor* overlappedActor, AActor* OtherActor);

public:
	FBoxLightBeingOverlap		OnBoxLightBeginOverlap;
};
