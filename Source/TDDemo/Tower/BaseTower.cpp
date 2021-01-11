// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseTower.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "TDDemo/Enemy/BaseEnemy.h"
#include "Components/SphereComponent.h"

// Sets default values
ABaseTower::ABaseTower()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AttackVolume = CreateDefaultSubobject<USphereComponent>(TEXT("AttackVolume"));
	RootComponent = AttackVolume;
	AttackVolume->InitSphereRadius(1600.0f);
	AttackVolume->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	AttackVolume->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	AttackVolume->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);

	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
	SkeletalMeshComponent->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void ABaseTower::BeginPlay()
{
	Super::BeginPlay();

	AttackVolume->OnComponentBeginOverlap.AddDynamic(this,&ABaseTower::OnOverlapBegin);
	AttackVolume->OnComponentEndOverlap.AddDynamic(this, &ABaseTower::OnOverlapEnd);
}

// Called every frame
void ABaseTower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	KeepRotation();
}

void ABaseTower::OnOverlapBegin(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor)
	{
		ABaseEnemy *Enemy = Cast<ABaseEnemy>(OtherActor);
		if (Enemy)
		{
			TargetEnemy = Enemy;
		}
	}
}

void ABaseTower::OnOverlapEnd(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{

}

void ABaseTower::KeepRotation()
{
	if (TargetEnemy)
	{
		SetActorRotation(FRotator(0.0f, UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), TargetEnemy->GetActorLocation()).Yaw - 90.0f, 0.0f));
	}
}



