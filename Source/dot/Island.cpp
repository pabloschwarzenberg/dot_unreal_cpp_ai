// Fill out your copyright notice in the Description page of Project Settings.


#include "Island.h"

// Sets default values
AIsland::AIsland(const FObjectInitializer& oi)
{
    PrimaryActorTick.bCanEverTick = false;
    box = oi.CreateDefaultSubobject<UBoxComponent>(this, TEXT("Box"));
    box->SetCollisionProfileName("BlockAll",true);
    RootComponent = box;
    mesh = oi.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh"));
    mesh->SetupAttachment(RootComponent);
    brick_class=nullptr;
    bricks=nullptr;
    cells=6;
    brick_size=40.0f;
}

AIsland::~AIsland()
{
    int i;
    if (bricks != nullptr)
    {
        for (i = 0; i < cells; i++)
            delete bricks[i];
        delete bricks;
    }
}

// Called when the game starts or when spawned
void AIsland::BeginPlay()
{
	Super::BeginPlay();
    Create();
}

void AIsland::Create()
{
    float x, y;
    FVector island_location = GetActorLocation();
    FVector location;
    int32 i, j, fila, columna;
    bool exito;
    Grid* generador;
    FString buffer;
    
    if(!brick_class)
        return;

    buffer = FString::Printf(TEXT("generando nivel\n"));
    if (GEngine)
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, buffer);

    generador = new Grid(cells);
    if (generador == nullptr)
        UE_LOG(LogTemp, Fatal, TEXT("Fallo en la creacion del generador"));

    generador->build();
    
    if(!logfile.IsEmpty())
    {
        exito = FFileHelper::SaveStringToFile(generador->serialize(), *(FPaths::ProjectDir() + logfile),
            FFileHelper::EEncodingOptions::AutoDetect, &IFileManager::Get(), EFileWrite::FILEWRITE_NoFail);
        if (!exito)
            UE_LOG(LogTemp, Warning, TEXT("No se pudo grabar el layout"));
    }

    bricks = new ABrick**[cells];
    if (bricks == nullptr)
        UE_LOG(LogTemp, Fatal, TEXT("No se pudo crear arreglo de bloques"));
    for (i = 0; i < cells; i++)
    {
        bricks[i] = new ABrick * [cells];
        for (j = 0; j < cells; j++)
            bricks[i][j] = nullptr;
    }

    i = 0;
    for (fila = -cells / 2; fila < cells / 2; fila++, i++)
    {
        x = fila * brick_size + brick_size / 2;
        j = 0;
        for (columna = -cells / 2; columna < cells / 2; columna++, j++)
        {
            y = columna * brick_size + brick_size / 2;
            location = FVector(x, y, 10.0f) + island_location;
            if (generador->isBrick(i, j))
                bricks[i][j] = GetWorld()->SpawnActor<ABrick>(brick_class, location, FRotator(0, 0, 0));
            else
                bricks[i][j] = nullptr;
        }
    }

    delete generador;
}

// Called every frame
void AIsland::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

