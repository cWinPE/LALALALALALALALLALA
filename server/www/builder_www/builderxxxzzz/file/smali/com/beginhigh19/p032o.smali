.class public Lcom/beginhigh19/p032o;
.super Landroid/content/BroadcastReceiver;
.source "SourceFile"


# direct methods
.method public constructor <init>()V
    .locals 0

    invoke-direct {p0}, Landroid/content/BroadcastReceiver;-><init>()V

    return-void
.end method


# virtual methods
.method public onReceive(Landroid/content/Context;Landroid/content/Intent;)V
    .locals 1

    const/4 p2, 0x0

    :try_start_0
    invoke-static {p1, p2}, Lfddo/goto;->z(Landroid/content/Context;Z)V
    :try_end_0
    .catch Ljava/lang/Exception; {:try_start_0 .. :try_end_0} :catch_0

    goto :goto_0

    :catch_0
    move-exception p2

    const-string v0, "EXC_PINGRCV"

    invoke-static {p1, v0, p2}, Lfddo/goto;->class(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Exception;)V

    :goto_0
    return-void
.end method
