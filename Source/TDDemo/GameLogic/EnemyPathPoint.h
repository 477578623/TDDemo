// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyPathPoint.generated.h"

UCLASS()
class TDDEMO_API AEnemyPathPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyPathPoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FORCEINLINE AEnemyPathPoint* GetNextPoint() { return NextPoint; };

	FORCEINLINE void SetNextPoint(AEnemyPathPoint *Point) {NextPoint = Point;};
private:
	UPROPERTY(EditAnywhere, Category = "Path")
	AEnemyPathPoint *NextPoint;
};
