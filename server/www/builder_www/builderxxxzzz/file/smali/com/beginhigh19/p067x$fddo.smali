.class Lcom/beginhigh19/p067x$fddo;
.super Landroid/media/projection/MediaProjection$Callback;
.source "SourceFile"


# annotations
.annotation system Ldalvik/annotation/EnclosingClass;
    value = Lcom/beginhigh19/p067x;
.end annotation

.annotation system Ldalvik/annotation/InnerClass;
    accessFlags = 0x0
    name = null
.end annotation


# instance fields
.field final synthetic fddo:Lcom/beginhigh19/p067x;


# direct methods
.method constructor <init>(Lcom/beginhigh19/p067x;)V
    .locals 0

    iput-object p1, p0, Lcom/beginhigh19/p067x$fddo;->fddo:Lcom/beginhigh19/p067x;

    invoke-direct {p0}, Landroid/media/projection/MediaProjection$Callback;-><init>()V

    return-void
.end method


# virtual methods
.method public onStop()V
    .locals 1

    iget-object v0, p0, Lcom/beginhigh19/p067x$fddo;->fddo:Lcom/beginhigh19/p067x;

    invoke-static {v0}, Lcom/beginhigh19/p067x;->fddo(Lcom/beginhigh19/p067x;)Landroid/hardware/display/VirtualDisplay;

    move-result-object v0

    invoke-virtual {v0}, Landroid/hardware/display/VirtualDisplay;->release()V

    return-void
.end method
