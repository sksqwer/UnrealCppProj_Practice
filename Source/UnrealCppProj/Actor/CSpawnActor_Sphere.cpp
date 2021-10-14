// Fill out your copyright notice in the Description page of Project Settings.


#include "CSpawnActor_Sphere.h"
#include "Global.h"

ACSpawnActor_Sphere::ACSpawnActor_Sphere()
{
	UStaticMesh* mesh;
	CHelpers::GetAsset<UStaticMesh>(&mesh, "StaticMesh'/Game/Meshes/Mesh_Sphere.Mesh_Sphere'");
	Mesh->SetStaticMesh(mesh);
}



