#include "MyProjectViewportClient.h"

#include "CanvasItem.h"
#include "Engine/Canvas.h"
#include "GlobalRenderResources.h"

UMyProjectViewportClient::UMyProjectViewportClient()
    : bShowCrosshair(true)
    , CrosshairStyle(ECrosshairStyle::Crosshair)
    , CrosshairColor(FLinearColor::White)
    , CrosshairSize(12.0f)
    , CrosshairThickness(2.0f)
    , CrosshairGap(6.0f)
    , DotSize(4.0f)
{
}

void UMyProjectViewportClient::Draw(FViewport* InViewport, FCanvas* SceneCanvas)
{
    Super::Draw(InViewport, SceneCanvas);

    if (!bShowCrosshair || InViewport == nullptr || SceneCanvas == nullptr)
    {
        return;
    }

    const FIntPoint ViewSize = InViewport->GetSizeXY();
    const FVector2D Center(ViewSize.X * 0.5f, ViewSize.Y * 0.5f);
    const FLinearColor DrawColor = CrosshairColor;

    if (CrosshairStyle == ECrosshairStyle::Dot)
    {
        if (GWhiteTexture != nullptr)
        {
            const FVector2D DotDimensions(DotSize, DotSize);
            const FVector2D DotTopLeft = Center - (DotDimensions * 0.5f);

            FCanvasTileItem DotItem(DotTopLeft, GWhiteTexture, DotDimensions, DrawColor);
            DotItem.BlendMode = SE_BLEND_Translucent;
            SceneCanvas->DrawItem(DotItem);
        }
        return;
    }

    auto DrawLine = [&](const FVector2D& Start, const FVector2D& End)
    {
        FCanvasLineItem LineItem(Start, End);
        LineItem.SetColor(DrawColor);
        LineItem.LineThickness = CrosshairThickness;
        SceneCanvas->DrawItem(LineItem);
    };

    DrawLine(
        FVector2D(Center.X - CrosshairGap - CrosshairSize, Center.Y),
        FVector2D(Center.X - CrosshairGap, Center.Y)
    );
    DrawLine(
        FVector2D(Center.X + CrosshairGap, Center.Y),
        FVector2D(Center.X + CrosshairGap + CrosshairSize, Center.Y)
    );
    DrawLine(
        FVector2D(Center.X, Center.Y - CrosshairGap - CrosshairSize),
        FVector2D(Center.X, Center.Y - CrosshairGap)
    );
    DrawLine(
        FVector2D(Center.X, Center.Y + CrosshairGap),
        FVector2D(Center.X, Center.Y + CrosshairGap + CrosshairSize)
    );
}
