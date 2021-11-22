// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "IRifle.h"
#include "CPlayer.generated.h"


UCLASS()
class UNREALCPPPROJ_API ACPlayer : public ACharacter, public IIRifle
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private :
	UPROPERTY(VisibleDefaultsOnly)
		class USpringArmComponent* SpringArm;

	UPROPERTY(EditDefaultsOnly, Category = "Widget")
		TSubclassOf<class UCUserWidget_CrossHair> CrossHairClass;


protected:
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly)
		class UCameraComponent* Camera;

private:
	void OnMoveForward(float Axis);
	void OnMoveRight(float Axis);

	void OnHorizontalLook(float Axis);
	void OnVerticalLook(float Axis);

	void OnRunning();
	void OffRunning();

	void OnRifle();

	void OnAim();
	void OffAim();

private:
	class UMaterialInstanceDynamic* BodyMaterial;
	class UMaterialInstanceDynamic* LogoMaterial;
	class UCUserWidget_CrossHair* CrossHair;

public:
	UFUNCTION(BlueprintCallable)
		void ChangeColor(FLinearColor InColor);

protected:
	UFUNCTION(BlueprintImplementableEvent)
		void OnZoomIn();

	UFUNCTION(BlueprintImplementableEvent)
		void OnZoomOut();

private:
	class ACRifle* Rifle;

public:
	FORCEINLINE class ACRifle* GetRifle() override { return Rifle; }

};
