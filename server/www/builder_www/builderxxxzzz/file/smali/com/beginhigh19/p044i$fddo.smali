.class Lcom/beginhigh19/p044i$fddo;
.super Ljava/lang/Object;
.source "SourceFile"

# interfaces
.implements Ljava/lang/Runnable;


# annotations
.annotation system Ldalvik/annotation/EnclosingMethod;
    value = Lcom/beginhigh19/p044i;->onStartCommand(Landroid/content/Intent;II)I
.end annotation

.annotation system Ldalvik/annotation/InnerClass;
    accessFlags = 0x0
    name = null
.end annotation


# instance fields
.field final synthetic fddo:Lcom/beginhigh19/p044i;


# direct methods
.method constructor <init>(Lcom/beginhigh19/p044i;)V
    .locals 0

    iput-object p1, p0, Lcom/beginhigh19/p044i$fddo;->fddo:Lcom/beginhigh19/p044i;

    invoke-direct {p0}, Ljava/lang/Object;-><init>()V

    return-void
.end method


# virtual methods
.method public run()V
    .locals 2

    invoke-static {}, Landroid/os/Looper;->prepare()V

    :cond_0
    :try_start_0
    iget-object v0, p0, Lcom/beginhigh19/p044i$fddo;->fddo:Lcom/beginhigh19/p044i;

    invoke-virtual {v0}, Landroid/app/Service;->getApplicationContext()Landroid/content/Context;

    move-result-object v1

    invoke-virtual {v0, v1}, Lcom/beginhigh19/p044i;->fddo(Landroid/content/Context;)V

    const-wide/16 v0, 0x3e8

    invoke-static {v0, v1}, Lfddo/goto;->p(J)V

    sget-boolean v0, Lcom/beginhigh19/p044i;->ifdf:Z
    :try_end_0
    .catch Ljava/lang/Exception; {:try_start_0 .. :try_end_0} :catch_0

    if-nez v0, :cond_0

    :catch_0
    return-void
.end method
