// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CEventTrigger.generated.h"

UCLASS()
class UNREALCPPPROJ_API ACEventTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACEventTrigger();

public:
	DECLARE_EVENT_OneParam(ACEventTrigger, FEventTrigger, int32);

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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	FEventTrigger	OnEventTrigger;

};
