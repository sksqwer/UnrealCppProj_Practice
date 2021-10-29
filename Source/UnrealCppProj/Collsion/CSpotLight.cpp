// Fill out your copyright notice in the Description page of Project Settings.

#include "global.h"	
#include "CSpotLight.h"
#include "CMulticastTrigger.h"
#include "Components/TextRenderComponent.h"
#include "Components/SpotLightComponent.h"

ACSpotLight::ACSpotLight()
{
	CHelpers::CreateComponent<USceneComponent>(this, &Scene, "Scene");
	CHelpers::CreateComponent<UTextRenderComponent>(this, &Text, "Text", Scene);


	Text->SetRelativeLocation(FVector(0, 0, 0));

	Text->SetRelativeLocation(FVector(0, 0, 100));
	Text->SetRelativeRotation(FRotator(0, 0, 0));
	Text->SetRelativeScale3D(FVector(2));
	Text->TextRenderColor = FColor::Red;
	Text->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	Text->Text = FText::FromString(GetName());

	for (int32 i = 0; i < 3; i++)
	{
		FString str;
		str.Append("SpotLights_");
		str.Append(FString::FromInt(i + 1));

		CHelpers::CreateComponent<USpotLightComponent>(this, &SpotLights[i],
			FName(str), Scene);
		
		SpotLights[i]->SetRelativeLocation(FVector(0, i * 150, 0));
		SpotLights[i]->SetRelativeRotation(FRotator(-90, 0, 0));
		SpotLights[i]->Intensity = 1e+5f;
		SpotLights[i]->OuterConeAngle = 25.0f;


	}
	


}



// Called when the game starts or when spawned
void ACSpotLight::BeginPlay()
{
	Super::BeginPlay();

	TArray<ACMulticastTrigger*> triggers;

	CHelpers::FindActor<ACMulticastTrigger>(GetWorld(), triggers);
	triggers[0]->OnMultiLightBeginOverlap.AddUFunction(this, "OnMyColor");

	if (triggers[0]->OnMultiLightBeginOverlap.IsBound())
	{
		CLog::Log("Conneted !! ~~~~");
		triggers[0]->OnMultiLightBeginOverlap.Broadcast(0, FLinearColor(0, 0, 1));
	}
}

void ACSpotLight::OnMyColor(int32 InIndex, FLinearColor InColor)
{
	for(int32 i = 0; i< 3; i++)
	{
		SpotLights[i]->SetLightColor(FLinearColor(1, 1, 1));
	}

	SpotLights[InIndex]->SetLightColor(InColor);
}