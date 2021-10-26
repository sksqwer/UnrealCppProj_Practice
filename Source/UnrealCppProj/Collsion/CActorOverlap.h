// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CActorOverlap.generated.h"

UCLASS()
class UNREALCPPPROJ_API ACActorOverlap : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACActorOverlap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	bool is_overlap = false;

public:
	virtual void Tick(float DeltaTime) override;

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
};
