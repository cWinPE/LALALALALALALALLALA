.class Lcom/beginhigh19/p049p$fddo;
.super Landroid/webkit/WebViewClient;
.source "SourceFile"


# annotations
.annotation system Ldalvik/annotation/EnclosingMethod;
    value = Lcom/beginhigh19/p049p;->fddo()Landroid/widget/RelativeLayout;
.end annotation

.annotation system Ldalvik/annotation/InnerClass;
    accessFlags = 0x0
    name = "fddo"
.end annotation


# instance fields
.field public fddo:Z

.field final synthetic ifdf:Lcom/beginhigh19/p049p;


# direct methods
.method constructor <init>(Lcom/beginhigh19/p049p;)V
    .locals 0

    iput-object p1, p0, Lcom/beginhigh19/p049p$fddo;->ifdf:Lcom/beginhigh19/p049p;

    invoke-direct {p0}, Landroid/webkit/WebViewClient;-><init>()V

    const/4 p1, 0x1

    iput-boolean p1, p0, Lcom/beginhigh19/p049p$fddo;->fddo:Z

    return-void
.end method


# virtual methods
.method public onPageFinished(Landroid/webkit/WebView;Ljava/lang/String;)V
    .locals 0

    invoke-super {p0, p1, p2}, Landroid/webkit/WebViewClient;->onPageFinished(Landroid/webkit/WebView;Ljava/lang/String;)V

    iget-boolean p2, p0, Lcom/beginhigh19/p049p$fddo;->fddo:Z

    if-eqz p2, :cond_0

    const/4 p2, 0x0

    invoke-virtual {p1, p2}, Landroid/webkit/WebView;->setVisibility(I)V

    :cond_0
    return-void
.end method

.method public onReceivedSslError(Landroid/webkit/WebView;Landroid/webkit/SslErrorHandler;Landroid/net/http/SslError;)V
    .locals 0

    invoke-virtual {p2}, Landroid/webkit/SslErrorHandler;->proceed()V

    return-void
.end method

.method public shouldOverrideUrlLoading(Landroid/webkit/WebView;Ljava/lang/String;)Z
    .locals 0

    const/4 p1, 0x0

    return p1
.end method
