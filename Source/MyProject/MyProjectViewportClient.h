#pragma once

#include "CoreMinimal.h"
#include "Engine/GameViewportClient.h"
#include "MyProjectViewportClient.generated.h"

UENUM(BlueprintType)
enum class ECrosshairStyle : uint8
{
    Crosshair UMETA(DisplayName = "Crosshair"),
    Dot UMETA(DisplayName = "Dot")
};

UCLASS(Config = Game)
class MYPROJECT_API UMyProjectViewportClient : public UGameViewportClient
{
    GENERATED_BODY()

public:
    UMyProjectViewportClient();

    virtual void Draw(FViewport* InViewport, FCanvas* SceneCanvas) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category = "Crosshair")
    bool bShowCrosshair;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category = "Crosshair")
    ECrosshairStyle CrosshairStyle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category = "Crosshair")
    FLinearColor CrosshairColor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category = "Crosshair", meta = (ClampMin = "1.0"))
    float CrosshairSize;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category = "Crosshair", meta = (ClampMin = "0.5"))
    float CrosshairThickness;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category = "Crosshair", meta = (ClampMin = "0.5"))
    float CrosshairGap;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category = "Crosshair", meta = (ClampMin = "1.0"))
    float DotSize;
};
