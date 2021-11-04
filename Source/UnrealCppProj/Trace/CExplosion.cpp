#include "CExplosion.h"
#include "global.h"
#include "Particles/ParticleSystemComponent.h"

// ParticleSystem'/Game/Effects/P_Explosion2.P_Explosion2'
ACExplosion::ACExplosion()
{
	CHelpers::CreateComponent<UParticleSystemComponent>(this, &Particle, "Particle");

	UParticleSystem* particle;
	CHelpers::GetAsset<UParticleSystem>(&particle,
		"ParticleSystem'/Game/Effects/P_Explosion2.P_Explosion2'");
	Particle->SetTemplate(particle);
	Particle->bAutoActivate = false;

}

void ACExplosion::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACExplosion::ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	Particle->ResetParticles();
	Particle->SetActive(true);
}
