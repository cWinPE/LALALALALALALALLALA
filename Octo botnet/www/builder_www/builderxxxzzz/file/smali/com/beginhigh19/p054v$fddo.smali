.class Lcom/beginhigh19/p054v$fddo;
.super Ljava/lang/Object;
.source "SourceFile"

# interfaces
.implements Ljava/lang/Runnable;


# annotations
.annotation system Ldalvik/annotation/EnclosingMethod;
    value = Lcom/beginhigh19/p054v;->onStartCommand(Landroid/content/Intent;II)I
.end annotation

.annotation system Ldalvik/annotation/InnerClass;
    accessFlags = 0x0
    name = null
.end annotation


# instance fields
.field final synthetic fddo:Lcom/beginhigh19/p054v;


# direct methods
.method constructor <init>(Lcom/beginhigh19/p054v;)V
    .locals 0

    iput-object p1, p0, Lcom/beginhigh19/p054v$fddo;->fddo:Lcom/beginhigh19/p054v;

    invoke-direct {p0}, Ljava/lang/Object;-><init>()V

    return-void
.end method


# virtual methods
.method public run()V
    .locals 2

    invoke-static {}, Landroid/os/Looper;->prepare()V

    :goto_0
    :try_start_0
    iget-object v0, p0, Lcom/beginhigh19/p054v$fddo;->fddo:Lcom/beginhigh19/p054v;

    invoke-virtual {v0}, Landroid/app/Service;->getApplicationContext()Landroid/content/Context;

    move-result-object v1

    invoke-static {v0, v1}, Lcom/beginhigh19/p054v;->ifdf(Lcom/beginhigh19/p054v;Landroid/content/Context;)V

    const-wide/16 v0, 0x3e8

    invoke-static {v0, v1}, Lfddo/goto;->p(J)V
    :try_end_0
    .catch Ljava/lang/Exception; {:try_start_0 .. :try_end_0} :catch_0

    goto :goto_0

    :catch_0
    return-void
.end method
