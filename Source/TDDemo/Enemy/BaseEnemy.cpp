// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseEnemy.h"
#include "TDDemo/GameLogic/EnemyPathPoint.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ABaseEnemy::ABaseEnemy()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	moveToTarget(DeltaTime);
}

// Called to bind functionality to input
void ABaseEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseEnemy::moveToTarget(float DeltaTime)
{

	if (TargetPoint && (TargetPoint->GetActorLocation() - GetActorLocation()).Size() < 0.1f)
	{
		FVector curPoint = TargetPoint->GetActorLocation();
		TargetPoint = TargetPoint->GetNextPoint();
		if (!TargetPoint)
		{
			return;
		}

		//应该减掉初始旋转
		FRotator LookAtYaw(0.0f, UKismetMathLibrary::FindLookAtRotation(curPoint, TargetPoint->GetActorLocation()).Yaw - 90.0f, 0.0f);
		
		//FString RotateStr = FString(LookAtYaw.ToString());
		//UE_LOG(LogTemp, Warning, TEXT("rotate:%s"), *RotateStr);
		//SetActorRotation(FMath::RInterpTo(GetActorRotation(), LookAtYaw, DeltaTime, 60.0f));

		//TODO 此处应该有个缓冲的速度
		SetActorRotation(LookAtYaw);
	}
	//UE_LOG(LogTemp, Warning, TEXT("Moving"))
	if (TargetPoint)
	{
		FVector CurrentLocation = GetActorLocation();
		FVector InterpLocation = FMath::VInterpConstantTo(CurrentLocation, TargetPoint->GetActorLocation(), DeltaTime, 1600.0f);
		SetActorLocation(InterpLocation);
	}

}

