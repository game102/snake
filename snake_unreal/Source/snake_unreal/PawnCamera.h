// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnCamera.generated.h"

UCLASS()
class SNAKE_UNREAL_API APawnCamera : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APawnCamera();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere)
	class USceneComponent* MyRootComponent;

	UPROPERTY(EditAnywhere)
	class USpringArmComponent* MyCameraSpring;

	UPROPERTY(EditAnywhere)
	class UCameraComponent* MyCamera;

	class ASnakeActor* SnakeInstance;

	void AddSnakeToMap();

	UPROPERTY(VisibleAnywhere)
	int32 Key;

	FVector2D WSDA;

	void ForwardMove(float ButtonVal);

	float MinY = -1500.f;
	float MinX = -800.f;

	float MaxY = 1500.f;
	float MaxX = 800.f;

	float SpawnZ = 50.f;

	void AddRandomApple();
};
