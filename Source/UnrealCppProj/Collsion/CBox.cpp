
#include "CBox.h"
#include "global.h"
#include "Components/TextRenderComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "CMulticastTrigger.h"

#include "Engine/StaticMeshSocket.h"

// Sets default values
ACBox::ACBox()
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

	UStaticMesh* mesh;
	CHelpers::GetAsset<UStaticMesh>(&mesh, "StaticMesh'/Game/Meshes/Mesh_Cube.Mesh_Cube'");

	for(int32 i = 0; i < 3; i++)
	{
		FString str;
		str.Append("Mesh_");
		str.Append(FString::FromInt(i + 1));

		CHelpers::CreateComponent<UStaticMeshComponent>(this, &Mesh[i], FName(str), Scene);
		Mesh[i]->SetRelativeLocation(FVector(0, i * 150, 0));
		Mesh[i]->SetStaticMesh(mesh);
		Mesh[i]->SetSimulatePhysics(false);

	}
}
// Called when the game starts or when spawned
void ACBox::BeginPlay()
{
	Super::BeginPlay();

	TArray<ACMulticastTrigger*> triggers;

	CHelpers::FindActor<ACMulticastTrigger>(GetWorld(), triggers);
	triggers[0]->OnMultiLightBeginOverlap.AddUFunction(this, "OnPhysics");

	UMaterialInstanceConstant* material;
	CHelpers::GetAssetDynamic<UMaterialInstanceConstant>(&material,
		"MaterialInstanceConstant'/Game/Material/Material_Mesh_Inst.Material_Mesh_Inst'");

	for(int32 i = 0; i < 3; i++)
	{
		Material[i] = UMaterialInstanceDynamic::Create(material, this);
		Mesh[i]->SetMaterial(0, Material[i]);
		FTransform transform = Mesh[i]->GetComponentToWorld();
		WorldLocation[i] = transform.GetLocation();
	}
}

void ACBox::OnPhysics(int32 InIndex, FLinearColor InColor)
{
	for(int32 i = 0; i < 3; i++)
	{
		Material[i]->SetVectorParameterValue("Color", FLinearColor(1, 1, 1));
		Mesh[i]->SetSimulatePhysics(false);
		Mesh[i]->SetWorldLocation(WorldLocation[i]);
		
	}

	Material[InIndex]->SetVectorParameterValue("Color", InColor);
	Mesh[InIndex]->SetSimulatePhysics(true);
}
