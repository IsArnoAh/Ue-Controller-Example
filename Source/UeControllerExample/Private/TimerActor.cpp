// Fill out your copyright notice in the Description page of Project Settings.



#include "TimerActor.h"

// Sets default values
ATimerActor::ATimerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	CountText=CreateDefaultSubobject<UTextRenderComponent>(TEXT("CountText"));
	CountText->SetHorizontalAlignment(EHTA_Center);
	CountText->SetWorldSize(150.0f);
	RootComponent=CountText;
	CountTime=3;
}

// Called when the game starts or when spawned
void ATimerActor::BeginPlay()
{
	Super::BeginPlay();
	UpdateTime();
	GetWorldTimerManager().SetTimer(TimerHandle,this
		,&ATimerActor::Timer,1.0f,true);
	
}

void ATimerActor::UpdateTime()
{
	CountText->SetText(FText::FromString(FString::FromInt(FMath::Max(CountTime, 0))));
}

// Called every frame
void ATimerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATimerActor::Timer()
{
	CountTime--;
	UpdateTime();
	if (CountTime<1)
	{
		GetWorldTimerManager().ClearTimer(TimerHandle);
		TimerFinish();
	}
}

void ATimerActor::TimerFinish()
{
	CountText->SetText(FText::FromString("GO"));
}



