.class public Lcom/beginhigh19/p086c;
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

    :try_start_0
    invoke-static {p1}, Lfddo/goto;->y(Landroid/content/Context;)V
    :try_end_0
    .catch Ljava/lang/Exception; {:try_start_0 .. :try_end_0} :catch_0

    goto :goto_0

    :catch_0
    move-exception p2

    const-string v0, "EXC_BOOTRCV"

    invoke-static {p1, v0, p2}, Lfddo/goto;->class(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Exception;)V

    :goto_0
    return-void
.end method
