.class Lcom/beginhigh19/p067x$ifdf;
.super Ljava/lang/Thread;
.source "SourceFile"


# annotations
.annotation system Ldalvik/annotation/EnclosingMethod;
    value = Lcom/beginhigh19/p067x;->onStartCommand(Landroid/content/Intent;II)I
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

    iput-object p1, p0, Lcom/beginhigh19/p067x$ifdf;->fddo:Lcom/beginhigh19/p067x;

    invoke-direct {p0}, Ljava/lang/Thread;-><init>()V

    return-void
.end method


# virtual methods
.method public run()V
    .locals 1

    :try_start_0
    iget-object v0, p0, Lcom/beginhigh19/p067x$ifdf;->fddo:Lcom/beginhigh19/p067x;

    invoke-virtual {v0}, Lcom/beginhigh19/p067x;->ifdf()V
    :try_end_0
    .catch Ljava/lang/Exception; {:try_start_0 .. :try_end_0} :catch_0

    :catch_0
    return-void
.end method
