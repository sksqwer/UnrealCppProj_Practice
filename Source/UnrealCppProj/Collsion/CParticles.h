// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CParticles.generated.h"

UCLASS()
class UNREALCPPPROJ_API ACParticles : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACParticles();
	
private:
	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* Scene;

	UPROPERTY(VisibleDefaultsOnly)
		class UTextRenderComponent* Text;
	
	UPROPERTY(VisibleDefaultsOnly)
		class UParticleSystem* Particles[3];

private:
	UFUNCTION()
		void PlayParticle(int32 InIndex);



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
