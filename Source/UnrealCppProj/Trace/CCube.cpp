
#include "CCube.h"
#include "global.h"
#include "Components/StaticMeshComponent.h"
#include "Components/TextRenderComponent.h"

ACCube::ACCube()
{
	CHelpers::CreateComponent<UStaticMeshComponent>(this, &Mesh, "Mesh");
	
	UStaticMesh* mesh;
	CHelpers::GetAsset<UStaticMesh>(&mesh, "StaticMesh'/Game/Meshes/Mesh_Cube.Mesh_Cube'");

	Mesh->SetStaticMesh(mesh);
	Mesh->SetSimulatePhysics(true);
	Mesh->SetCollisionObjectType(ECollisionChannel::ECC_PhysicsBody);

}

void ACCube::BeginPlay()
{
	Super::BeginPlay();
	
}